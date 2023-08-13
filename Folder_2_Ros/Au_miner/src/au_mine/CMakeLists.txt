cmake_minimum_required(VERSION 3.8)
project(au_mine)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(au_interfaces REQUIRED)
find_package(rclcpp_action REQUIRED)

add_executable(au_world src/au_world.cpp)
add_executable(au_miner src/au_miner.cpp)
target_include_directories(au_world PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_include_directories(au_miner PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)
target_compile_features(au_world PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_compile_features(au_miner PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  au_world
  "rclcpp"
  "au_interfaces"
  "rclcpp_action"
)
ament_target_dependencies(
  au_miner
  "rclcpp"
  "au_interfaces"
  "rclcpp_action"
)

install(TARGETS au_world au_miner
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
