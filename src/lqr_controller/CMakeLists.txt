cmake_minimum_required(VERSION 3.8)
project(lqr_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
set(THIS_PACKAGE_INCLUDE_DEPENDS
  control_msgs
  controller_interface
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
  realtime_tools
  std_srvs
  tf2_ros
  tf2
  tf2_geometry_msgs
  sensor_msgs
  geometry_msgs
  robot_state_pub_interface
)

find_package(ament_cmake REQUIRED)
find_package(generate_parameter_library REQUIRED)
find_package(ament_cmake_gmock REQUIRED)
find_package(controller_manager REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(ros2_control_test_assets REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)  # 添加这一行
find_package(controller_interface REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(robot_state_pub_interface REQUIRED)

foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

# Add lqr_controller library related compile commands
generate_parameter_library(lqr_controller_parameters
  src/lqr_controller.yaml
  include/lqr_controller/validate_lqr_controller_parameters.hpp
)
add_library(
  lqr_controller
  SHARED
  src/lqr_controller.cpp
)
target_include_directories(lqr_controller PUBLIC
  "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>")
target_link_libraries(lqr_controller lqr_controller_parameters)
ament_target_dependencies(lqr_controller ${THIS_PACKAGE_INCLUDE_DEPENDS})
target_compile_definitions(lqr_controller PRIVATE "LQR_CONTROLLER_BUILDING_DLL")

pluginlib_export_plugin_description_file(
  controller_interface lqr_controller.xml)

install(
  TARGETS
  lqr_controller
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

ament_export_include_directories(
  include
)
ament_export_dependencies(
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
ament_export_libraries(
  lqr_controller
)

ament_package()
