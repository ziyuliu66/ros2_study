// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_state_pub_interface:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
#define ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_state_pub_interface__msg__RobotState __attribute__((deprecated))
#else
# define DEPRECATED__robot_state_pub_interface__msg__RobotState __declspec(deprecated)
#endif

namespace robot_state_pub_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotState_
{
  using Type = RobotState_<ContainerAllocator>;

  explicit RobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _joint_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _joint_names_type joint_names;
  using _angles_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _angles_type angles;
  using _set_effort_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _set_effort_type set_effort;

  // setters for named parameter idiom
  Type & set__joint_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->joint_names = _arg;
    return *this;
  }
  Type & set__angles(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->angles = _arg;
    return *this;
  }
  Type & set__set_effort(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->set_effort = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_state_pub_interface::msg::RobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_state_pub_interface::msg::RobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_state_pub_interface::msg::RobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_state_pub_interface::msg::RobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_state_pub_interface__msg__RobotState
    std::shared_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_state_pub_interface__msg__RobotState
    std::shared_ptr<robot_state_pub_interface::msg::RobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotState_ & other) const
  {
    if (this->joint_names != other.joint_names) {
      return false;
    }
    if (this->angles != other.angles) {
      return false;
    }
    if (this->set_effort != other.set_effort) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotState_

// alias to use template instance with default allocator
using RobotState =
  robot_state_pub_interface::msg::RobotState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_state_pub_interface

#endif  // ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
