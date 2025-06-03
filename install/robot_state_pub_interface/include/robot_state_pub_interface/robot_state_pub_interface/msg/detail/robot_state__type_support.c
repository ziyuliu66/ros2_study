// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_state_pub_interface:msg/RobotState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_state_pub_interface/msg/detail/robot_state__rosidl_typesupport_introspection_c.h"
#include "robot_state_pub_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_state_pub_interface/msg/detail/robot_state__functions.h"
#include "robot_state_pub_interface/msg/detail/robot_state__struct.h"


// Include directives for member types
// Member `joint_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `angles`
// Member `set_effort`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_state_pub_interface__msg__RobotState__init(message_memory);
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_fini_function(void * message_memory)
{
  robot_state_pub_interface__msg__RobotState__fini(message_memory);
}

size_t robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__joint_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__joint_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__joint_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__joint_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__joint_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__joint_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__joint_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__joint_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__angles(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__angles(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__angles(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__angles(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__angles(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__angles(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__set_effort(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__set_effort(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__set_effort(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__set_effort(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__set_effort(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__set_effort(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__set_effort(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__set_effort(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_member_array[3] = {
  {
    "joint_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_state_pub_interface__msg__RobotState, joint_names),  // bytes offset in struct
    NULL,  // default value
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__joint_names,  // size() function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__joint_names,  // get_const(index) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__joint_names,  // get(index) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__joint_names,  // fetch(index, &value) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__joint_names,  // assign(index, value) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__joint_names  // resize(index) function pointer
  },
  {
    "angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_state_pub_interface__msg__RobotState, angles),  // bytes offset in struct
    NULL,  // default value
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__angles,  // size() function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__angles,  // get_const(index) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__angles,  // get(index) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__angles,  // fetch(index, &value) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__angles,  // assign(index, value) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__angles  // resize(index) function pointer
  },
  {
    "set_effort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_state_pub_interface__msg__RobotState, set_effort),  // bytes offset in struct
    NULL,  // default value
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__size_function__RobotState__set_effort,  // size() function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_const_function__RobotState__set_effort,  // get_const(index) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__get_function__RobotState__set_effort,  // get(index) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__fetch_function__RobotState__set_effort,  // fetch(index, &value) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__assign_function__RobotState__set_effort,  // assign(index, value) function pointer
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__resize_function__RobotState__set_effort  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_members = {
  "robot_state_pub_interface__msg",  // message namespace
  "RobotState",  // message name
  3,  // number of fields
  sizeof(robot_state_pub_interface__msg__RobotState),
  robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_member_array,  // message members
  robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle = {
  0,
  &robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_state_pub_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_state_pub_interface, msg, RobotState)() {
  if (!robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle.typesupport_identifier) {
    robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_state_pub_interface__msg__RobotState__rosidl_typesupport_introspection_c__RobotState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
