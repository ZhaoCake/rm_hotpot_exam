cmake_minimum_required(VERSION 3.8)
project(tf_exam)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

add_executable(exam_3_3_1 src/exam_3_3_1.cpp)
# add_executable(exam_3_3_2 src/exam_3_3_2.cpp)
target_include_directories(exam_3_3_1 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(exam_3_3_1 PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  exam_3_3_1
  "rclcpp"
  "tf2"
  "tf2_ros"
  "geometry_msgs"
)
# ament_target_dependencies(
#   exam_3_3_2
#   "rclcpp"
#   "tf2"
#   "tf2_ros"
#   "geometry_msgs"
# )

install(TARGETS
  exam_3_3_1
  # exam_3_3_2
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
