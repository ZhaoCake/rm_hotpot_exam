// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from mineral_interfaces:msg/MineralArray.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "mineral_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "mineral_interfaces/msg/detail/mineral_array__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace mineral_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mineral_interfaces
cdr_serialize(
  const mineral_interfaces::msg::MineralArray & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mineral_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mineral_interfaces::msg::MineralArray & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mineral_interfaces
get_serialized_size(
  const mineral_interfaces::msg::MineralArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mineral_interfaces
max_serialized_size_MineralArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mineral_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mineral_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mineral_interfaces, msg, MineralArray)();

#ifdef __cplusplus
}
#endif

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
