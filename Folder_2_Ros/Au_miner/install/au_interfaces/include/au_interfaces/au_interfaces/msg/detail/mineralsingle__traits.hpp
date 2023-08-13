// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__TRAITS_HPP_
#define AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "au_interfaces/msg/detail/mineralsingle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace au_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Mineralsingle & msg,
  std::ostream & out)
{
  out << "{";
  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: kind
  {
    out << "kind: ";
    rosidl_generator_traits::value_to_yaml(msg.kind, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: price
  {
    out << "price: ";
    rosidl_generator_traits::value_to_yaml(msg.price, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineralsingle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: kind
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kind: ";
    rosidl_generator_traits::value_to_yaml(msg.kind, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: price
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "price: ";
    rosidl_generator_traits::value_to_yaml(msg.price, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineralsingle & msg, bool use_flow_style = false)
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

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::msg::Mineralsingle & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::msg::Mineralsingle & msg)
{
  return au_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::msg::Mineralsingle>()
{
  return "au_interfaces::msg::Mineralsingle";
}

template<>
inline const char * name<au_interfaces::msg::Mineralsingle>()
{
  return "au_interfaces/msg/Mineralsingle";
}

template<>
struct has_fixed_size<au_interfaces::msg::Mineralsingle>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<au_interfaces::msg::Mineralsingle>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<au_interfaces::msg::Mineralsingle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__TRAITS_HPP_
