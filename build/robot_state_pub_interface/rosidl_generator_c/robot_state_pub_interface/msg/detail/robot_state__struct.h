// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_state_pub_interface:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_names'
#include "rosidl_runtime_c/string.h"
// Member 'angles'
// Member 'set_effort'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RobotState in the package robot_state_pub_interface.
typedef struct robot_state_pub_interface__msg__RobotState
{
  rosidl_runtime_c__String__Sequence joint_names;
  rosidl_runtime_c__double__Sequence angles;
  rosidl_runtime_c__double__Sequence set_effort;
} robot_state_pub_interface__msg__RobotState;

// Struct for a sequence of robot_state_pub_interface__msg__RobotState.
typedef struct robot_state_pub_interface__msg__RobotState__Sequence
{
  robot_state_pub_interface__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_state_pub_interface__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_STATE_PUB_INTERFACE__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
