// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_state_pub_interface:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_state_pub_interface/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_state_pub_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_names
  {
    if (msg.joint_names.size() == 0) {
      out << "joint_names: []";
    } else {
      out << "joint_names: [";
      size_t pending_items = msg.joint_names.size();
      for (auto item : msg.joint_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: angles
  {
    if (msg.angles.size() == 0) {
      out << "angles: []";
    } else {
      out << "angles: [";
      size_t pending_items = msg.angles.size();
      for (auto item : msg.angles) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: set_effort
  {
    if (msg.set_effort.size() == 0) {
      out << "set_effort: []";
    } else {
      out << "set_effort: [";
      size_t pending_items = msg.set_effort.size();
      for (auto item : msg.set_effort) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_names.size() == 0) {
      out << "joint_names: []\n";
    } else {
      out << "joint_names:\n";
      for (auto item : msg.joint_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angles.size() == 0) {
      out << "angles: []\n";
    } else {
      out << "angles:\n";
      for (auto item : msg.angles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: set_effort
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.set_effort.size() == 0) {
      out << "set_effort: []\n";
    } else {
      out << "set_effort:\n";
      for (auto item : msg.set_effort) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_state_pub_interface

namespace rosidl_generator_traits
{

[[deprecated("use robot_state_pub_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_state_pub_interface::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_state_pub_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_state_pub_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_state_pub_interface::msg::RobotState & msg)
{
  return robot_state_pub_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_state_pub_interface::msg::RobotState>()
{
  return "robot_state_pub_interface::msg::RobotState";
}

template<>
inline const char * name<robot_state_pub_interface::msg::RobotState>()
{
  return "robot_state_pub_interface/msg/RobotState";
}

template<>
struct has_fixed_size<robot_state_pub_interface::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_state_pub_interface::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_state_pub_interface::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
