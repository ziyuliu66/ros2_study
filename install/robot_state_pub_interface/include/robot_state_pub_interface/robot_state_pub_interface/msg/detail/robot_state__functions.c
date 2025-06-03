// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_state_pub_interface:msg/RobotState.idl
// generated code does not contain a copyright notice
#include "robot_state_pub_interface/msg/detail/robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joint_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `angles`
// Member `set_effort`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robot_state_pub_interface__msg__RobotState__init(robot_state_pub_interface__msg__RobotState * msg)
{
  if (!msg) {
    return false;
  }
  // joint_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->joint_names, 0)) {
    robot_state_pub_interface__msg__RobotState__fini(msg);
    return false;
  }
  // angles
  if (!rosidl_runtime_c__double__Sequence__init(&msg->angles, 0)) {
    robot_state_pub_interface__msg__RobotState__fini(msg);
    return false;
  }
  // set_effort
  if (!rosidl_runtime_c__double__Sequence__init(&msg->set_effort, 0)) {
    robot_state_pub_interface__msg__RobotState__fini(msg);
    return false;
  }
  return true;
}

void
robot_state_pub_interface__msg__RobotState__fini(robot_state_pub_interface__msg__RobotState * msg)
{
  if (!msg) {
    return;
  }
  // joint_names
  rosidl_runtime_c__String__Sequence__fini(&msg->joint_names);
  // angles
  rosidl_runtime_c__double__Sequence__fini(&msg->angles);
  // set_effort
  rosidl_runtime_c__double__Sequence__fini(&msg->set_effort);
}

bool
robot_state_pub_interface__msg__RobotState__are_equal(const robot_state_pub_interface__msg__RobotState * lhs, const robot_state_pub_interface__msg__RobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->joint_names), &(rhs->joint_names)))
  {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  // set_effort
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->set_effort), &(rhs->set_effort)))
  {
    return false;
  }
  return true;
}

bool
robot_state_pub_interface__msg__RobotState__copy(
  const robot_state_pub_interface__msg__RobotState * input,
  robot_state_pub_interface__msg__RobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->joint_names), &(output->joint_names)))
  {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  // set_effort
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->set_effort), &(output->set_effort)))
  {
    return false;
  }
  return true;
}

robot_state_pub_interface__msg__RobotState *
robot_state_pub_interface__msg__RobotState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_state_pub_interface__msg__RobotState * msg = (robot_state_pub_interface__msg__RobotState *)allocator.allocate(sizeof(robot_state_pub_interface__msg__RobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_state_pub_interface__msg__RobotState));
  bool success = robot_state_pub_interface__msg__RobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_state_pub_interface__msg__RobotState__destroy(robot_state_pub_interface__msg__RobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_state_pub_interface__msg__RobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_state_pub_interface__msg__RobotState__Sequence__init(robot_state_pub_interface__msg__RobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_state_pub_interface__msg__RobotState * data = NULL;

  if (size) {
    data = (robot_state_pub_interface__msg__RobotState *)allocator.zero_allocate(size, sizeof(robot_state_pub_interface__msg__RobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_state_pub_interface__msg__RobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_state_pub_interface__msg__RobotState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_state_pub_interface__msg__RobotState__Sequence__fini(robot_state_pub_interface__msg__RobotState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_state_pub_interface__msg__RobotState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_state_pub_interface__msg__RobotState__Sequence *
robot_state_pub_interface__msg__RobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_state_pub_interface__msg__RobotState__Sequence * array = (robot_state_pub_interface__msg__RobotState__Sequence *)allocator.allocate(sizeof(robot_state_pub_interface__msg__RobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_state_pub_interface__msg__RobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_state_pub_interface__msg__RobotState__Sequence__destroy(robot_state_pub_interface__msg__RobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_state_pub_interface__msg__RobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_state_pub_interface__msg__RobotState__Sequence__are_equal(const robot_state_pub_interface__msg__RobotState__Sequence * lhs, const robot_state_pub_interface__msg__RobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_state_pub_interface__msg__RobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_state_pub_interface__msg__RobotState__Sequence__copy(
  const robot_state_pub_interface__msg__RobotState__Sequence * input,
  robot_state_pub_interface__msg__RobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_state_pub_interface__msg__RobotState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_state_pub_interface__msg__RobotState * data =
      (robot_state_pub_interface__msg__RobotState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_state_pub_interface__msg__RobotState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_state_pub_interface__msg__RobotState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_state_pub_interface__msg__RobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
