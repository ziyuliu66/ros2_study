// Copyright (c) 2022, Stogl Robotics Consulting UG (haftungsbeschränkt) (template)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Source of this file are templates in
// [RosTeamWorkspace](https://github.com/StoglRobotics/ros_team_workspace) repository.
//

#include "lqr_controller/lqr_controller.hpp"

#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "controller_interface/helpers.hpp"

namespace
{  // utility

// TODO(destogl): remove this when merged upstream
// Changed services history QoS to keep all so we don't lose any client service calls
static constexpr rmw_qos_profile_t rmw_qos_profile_services_hist_keep_all = {
  RMW_QOS_POLICY_HISTORY_KEEP_ALL,
  1,  // message queue depth
  RMW_QOS_POLICY_RELIABILITY_RELIABLE,
  RMW_QOS_POLICY_DURABILITY_VOLATILE,
  RMW_QOS_DEADLINE_DEFAULT,
  RMW_QOS_LIFESPAN_DEFAULT,
  RMW_QOS_POLICY_LIVELINESS_SYSTEM_DEFAULT,
  RMW_QOS_LIVELINESS_LEASE_DURATION_DEFAULT,
  false};

using ControllerReferenceMsg = lqr_controller::LqrController::ControllerReferenceMsg;

// called from RT control loop
void reset_controller_reference_msg(
  std::shared_ptr<ControllerReferenceMsg> & msg, const std::vector<std::string> & joint_names)
{
  msg->joint_names = joint_names;
  msg->displacements.resize(joint_names.size(), std::numeric_limits<double>::quiet_NaN());
  msg->velocities.resize(joint_names.size(), std::numeric_limits<double>::quiet_NaN());
  msg->duration = std::numeric_limits<double>::quiet_NaN();
}

}  // namespace

namespace lqr_controller
{
LqrController::LqrController() : controller_interface::ControllerInterface() {}

controller_interface::CallbackReturn LqrController::on_init()
{
  control_mode_.initRT(control_mode_type::FAST);

  try
  {
    param_listener_ = std::make_shared<lqr_controller::ParamListener>(get_node());
  }
  catch (const std::exception & e)
  {
    fprintf(stderr, "Exception thrown during controller's init with message: %s \n", e.what());
    return controller_interface::CallbackReturn::ERROR;
  }

  return controller_interface::CallbackReturn::SUCCESS;
}

controller_interface::CallbackReturn LqrController::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  params_ = param_listener_->get_params();

  if (!params_.state_joints.empty())
  {
    state_joints_ = params_.state_joints;
  }
  else
  {
    state_joints_ = params_.joints;
  }

  if (params_.joints.size() != state_joints_.size())
  {
    RCLCPP_FATAL(
      get_node()->get_logger(),
      "Size of 'joints' (%zu) and 'state_joints' (%zu) parameters has to be the same!",
      params_.joints.size(), state_joints_.size());
    return CallbackReturn::FAILURE;
  }

  // topics QoS
  auto subscribers_qos = rclcpp::SystemDefaultsQoS();
  subscribers_qos.keep_last(1);
  subscribers_qos.best_effort();

  // Reference Subscriber
  ref_subscriber_ = get_node()->create_subscription<ControllerReferenceMsg>(
    "~/reference", subscribers_qos,
    std::bind(&LqrController::reference_callback, this, std::placeholders::_1));

  imu_subscriber_ = get_node()->create_subscription<sensor_msgs::msg::Imu>(
    "imu", subscribers_qos,
    std::bind(&LqrController::imu_callback, this, std::placeholders::_1));

  joint_states_subscriber_ = get_node()->create_subscription<sensor_msgs::msg::JointState>(
    "joint_states", subscribers_qos,
    std::bind(&LqrController::joint_states_callback, this, std::placeholders::_1));

  desired_states_subscriber_ = get_node()->create_subscription<geometry_msgs::msg::Twist>(
    "cmd_vel", subscribers_qos,
    std::bind(&LqrController::desired_states_callback, this, std::placeholders::_1));
    
  std::shared_ptr<ControllerReferenceMsg> msg = std::make_shared<ControllerReferenceMsg>();
  reset_controller_reference_msg(msg, params_.joints);
  input_ref_.writeFromNonRT(msg);

  auto set_slow_mode_service_callback =
    [&](
      const std::shared_ptr<ControllerModeSrvType::Request> request,
      std::shared_ptr<ControllerModeSrvType::Response> response)
  {
    if (request->data)
    {
      control_mode_.writeFromNonRT(control_mode_type::SLOW);
    }
    else
    {
      control_mode_.writeFromNonRT(control_mode_type::FAST);
    }
    response->success = true;
  };

  set_slow_control_mode_service_ = get_node()->create_service<ControllerModeSrvType>(
    "~/set_slow_control_mode", set_slow_mode_service_callback,
    rmw_qos_profile_services_hist_keep_all);

  try
  {
    // State publisher
    s_publisher_ =
      get_node()->create_publisher<ControllerStateMsg>("~/state", rclcpp::SystemDefaultsQoS());
    state_publisher_ = std::make_unique<ControllerStatePublisher>(s_publisher_);
  }
  catch (const std::exception & e)
  {
    fprintf(
      stderr, "Exception thrown during publisher creation at configure stage with message : %s \n",
      e.what());
    return controller_interface::CallbackReturn::ERROR;
  }

  // TODO(anyone): Reserve memory in state publisher depending on the message type
  state_publisher_->lock();
  state_publisher_->msg_.header.frame_id = params_.joints[0];
  state_publisher_->unlock();

  RCLCPP_INFO(get_node()->get_logger(), "configure successful");
  return controller_interface::CallbackReturn::SUCCESS;
}

void LqrController::reference_callback(const std::shared_ptr<ControllerReferenceMsg> msg)
{
  if (msg->joint_names.size() == params_.joints.size())
  {
    input_ref_.writeFromNonRT(msg);
  }
  else
  {
    RCLCPP_ERROR(
      get_node()->get_logger(),
      "Received %zu , but expected %zu joints in command. Ignoring message.",
      msg->joint_names.size(), params_.joints.size());
  }
}

void LqrController::imu_callback(const std::shared_ptr<sensor_msgs::msg::Imu> msg)
{
  // 提取四元数
  tf2::Quaternion quat(msg->orientation.x , msg->orientation.y , msg->orientation.z , msg->orientation.w);
  // 转换为欧拉角 (弧度)
  tf2::Matrix3x3 mat(quat);
  double roll, pitch, yaw;
  mat.getRPY(roll, pitch, yaw);
  euler_roll_ = roll;
  euler_pitch_ = pitch;
  euler_yaw_ = yaw;

  euler_roll_velocity_ = msg->angular_velocity.x;
  euler_pitch_velocity_ = msg->angular_velocity.y;
  euler_yaw_velocity_ = msg->angular_velocity.z;

  x_acceleration_ = msg->linear_acceleration.x;
  y_acceleration_ = msg->linear_acceleration.y;
  z_acceleration_ = msg->linear_acceleration.z;
}

void LqrController::joint_states_callback(const std::shared_ptr<sensor_msgs::msg::JointState> msg)
{
  left_wheel_velocity_ = msg->velocity[0];
  right_wheel_velocity_ = msg->velocity[1];
  left_wheel_effort_= msg->effort[0];
  right_wheel_effort_ = msg->effort[1];
}

void LqrController::desired_states_callback(const std::shared_ptr<geometry_msgs::msg::Twist> msg)
{
  v_set_ = msg->linear.x;
  z_set_ = msg->angular.z;
}

controller_interface::InterfaceConfiguration LqrController::command_interface_configuration() const
{
  controller_interface::InterfaceConfiguration command_interfaces_config;
  command_interfaces_config.type = controller_interface::interface_configuration_type::INDIVIDUAL;

  command_interfaces_config.names.reserve(params_.joints.size());
  for (const auto & joint : params_.joints)
  {
    command_interfaces_config.names.push_back(joint + "/" + params_.interface_name);
  }

  return command_interfaces_config;
}

controller_interface::InterfaceConfiguration LqrController::state_interface_configuration() const
{
  controller_interface::InterfaceConfiguration state_interfaces_config;
  state_interfaces_config.type = controller_interface::interface_configuration_type::INDIVIDUAL;

  state_interfaces_config.names.reserve(state_joints_.size());
  for (const auto & joint : state_joints_)
  {
    state_interfaces_config.names.push_back(joint + "/" + params_.interface_name);
  }

  return state_interfaces_config;
}

controller_interface::CallbackReturn LqrController::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO(anyone): if you have to manage multiple interfaces that need to be sorted check
  // `on_activate` method in `JointTrajectoryController` for exemplary use of
  // `controller_interface::get_ordered_interfaces` helper function

  // Set default value in command
  reset_controller_reference_msg(*(input_ref_.readFromRT)(), params_.joints);

  return controller_interface::CallbackReturn::SUCCESS;
}

controller_interface::CallbackReturn LqrController::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // TODO(anyone): depending on number of interfaces, use definitions, e.g., `CMD_MY_ITFS`,
  // instead of a loop
  for (size_t i = 0; i < command_interfaces_.size(); ++i)
  {
    command_interfaces_[i].set_value(std::numeric_limits<double>::quiet_NaN());
  }
  return controller_interface::CallbackReturn::SUCCESS;
}

controller_interface::return_type LqrController::update(
  const rclcpp::Time & time, const rclcpp::Duration & /*period*/)
{
  auto current_ref = input_ref_.readFromRT();
  float euler_angle[3] = {euler_roll_,euler_pitch_,euler_yaw_};
  float euler_angle_velocity[3] = {euler_roll_velocity_,euler_pitch_velocity_,euler_yaw_velocity_};
  float wheel_velocity[2] = {left_wheel_velocity_,left_wheel_velocity_};

  float k_yaw = 2.0;
  float K[4] = {-22.6130,-4.5769,-3.4641,-3.9337};//theta d_theta x d_x

  car_mean_velocity_ = (left_wheel_velocity_*wheel_radius + left_wheel_velocity_*wheel_radius)/2-v_set_;
  car_mean_displacement_ += car_mean_velocity_ *(1/30);

  float left_wheel_set_effort = K[0]*euler_pitch_+K[1]*euler_pitch_velocity_+K[2]*car_mean_displacement_+K[3]*car_mean_velocity_-k_yaw*(euler_yaw_velocity_-z_set_);
  float right_wheel_set_effort = K[0]*euler_pitch_+K[1]*euler_pitch_velocity_+K[2]*car_mean_displacement_+K[3]*car_mean_velocity_+k_yaw*(euler_yaw_velocity_-z_set_);

  float set_effort[2] = {-left_wheel_set_effort,-right_wheel_set_effort};

  // TODO(anyone): depending on number of interfaces, use definitions, e.g., `CMD_MY_ITFS`,
  // instead of a loop
  for (size_t i = 0; i < command_interfaces_.size(); ++i)
  {
    // if (!std::isnan((*current_ref)->displacements[i]))
    // {
    //   if (*(control_mode_.readFromRT()) == control_mode_type::SLOW)
    //   {
    //     (*current_ref)->displacements[i] /= 2;
    //   }
      command_interfaces_[i].set_value(set_effort[i]/*(*current_ref)->displacements[i]*/);

    // (*current_ref)->displacements[i] = std::numeric_limits<double>::quiet_NaN();
    // }
  }

  if (state_publisher_ && state_publisher_->trylock())
  {
    state_publisher_->msg_.joint_names.clear();
    state_publisher_->msg_.displacements.clear();
    state_publisher_->msg_.velocities.clear();

    for(size_t i = 0; i < state_interfaces_.size(); ++i)
    {
      state_publisher_->msg_.joint_names.emplace_back(state_interfaces_[i].get_name());
    }
    for(int j = 0; j < 3; ++j)
    {
      state_publisher_->msg_.velocities.emplace_back(euler_angle[j]*rad2angle);
    }
    state_publisher_->msg_.displacements.emplace_back(left_wheel_effort_);
    state_publisher_->msg_.displacements.emplace_back(right_wheel_effort_);
    state_publisher_->msg_.header.stamp = time;
    state_publisher_->unlockAndPublish();
  }

  return controller_interface::return_type::OK;
}

}  // namespace lqr_controller

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
  lqr_controller::LqrController, controller_interface::ControllerInterface)
