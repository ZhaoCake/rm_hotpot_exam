// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "au_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "au_interfaces/msg/detail/mineralsingle__struct.hpp"

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

namespace au_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_au_interfaces
cdr_serialize(
  const au_interfaces::msg::Mineralsingle & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_au_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  au_interfaces::msg::Mineralsingle & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_au_interfaces
get_serialized_size(
  const au_interfaces::msg::Mineralsingle & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_au_interfaces
max_serialized_size_Mineralsingle(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace au_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_au_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, au_interfaces, msg, Mineralsingle)();

#ifdef __cplusplus
}
#endif

#endif  // AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
