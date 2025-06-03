// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_state_pub_interface:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_state_pub_interface/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_state_pub_interface
{

namespace msg
{

namespace builder
{

class Init_RobotState_set_effort
{
public:
  explicit Init_RobotState_set_effort(::robot_state_pub_interface::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::robot_state_pub_interface::msg::RobotState set_effort(::robot_state_pub_interface::msg::RobotState::_set_effort_type arg)
  {
    msg_.set_effort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_state_pub_interface::msg::RobotState msg_;
};

class Init_RobotState_angles
{
public:
  explicit Init_RobotState_angles(::robot_state_pub_interface::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_set_effort angles(::robot_state_pub_interface::msg::RobotState::_angles_type arg)
  {
    msg_.angles = std::move(arg);
    return Init_RobotState_set_effort(msg_);
  }

private:
  ::robot_state_pub_interface::msg::RobotState msg_;
};

class Init_RobotState_joint_names
{
public:
  Init_RobotState_joint_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_angles joint_names(::robot_state_pub_interface::msg::RobotState::_joint_names_type arg)
  {
    msg_.joint_names = std::move(arg);
    return Init_RobotState_angles(msg_);
  }

private:
  ::robot_state_pub_interface::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_state_pub_interface::msg::RobotState>()
{
  return robot_state_pub_interface::msg::builder::Init_RobotState_joint_names();
}

}  // namespace robot_state_pub_interface

#endif  // ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
