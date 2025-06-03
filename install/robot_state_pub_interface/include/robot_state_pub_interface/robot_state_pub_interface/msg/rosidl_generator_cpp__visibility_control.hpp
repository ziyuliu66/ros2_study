// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef ROBOT_STATE_PUB_INTERFACE__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define ROBOT_STATE_PUB_INTERFACE__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_robot_state_pub_interface __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_robot_state_pub_interface __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_robot_state_pub_interface __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_robot_state_pub_interface __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_robot_state_pub_interface
    #define ROSIDL_GENERATOR_CPP_PUBLIC_robot_state_pub_interface ROSIDL_GENERATOR_CPP_EXPORT_robot_state_pub_interface
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_robot_state_pub_interface ROSIDL_GENERATOR_CPP_IMPORT_robot_state_pub_interface
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_robot_state_pub_interface __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_robot_state_pub_interface
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_robot_state_pub_interface __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_robot_state_pub_interface
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_STATE_PUB_INTERFACE__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
