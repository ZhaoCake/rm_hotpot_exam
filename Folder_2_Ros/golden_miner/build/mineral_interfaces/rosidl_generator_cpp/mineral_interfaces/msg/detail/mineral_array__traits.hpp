// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mineral_interfaces:msg/MineralArray.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__TRAITS_HPP_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mineral_interfaces/msg/detail/mineral_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'head'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'minerals'
#include "mineral_interfaces/msg/detail/mineral__traits.hpp"

namespace mineral_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MineralArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: head
  {
    out << "head: ";
    to_flow_style_yaml(msg.head, out);
    out << ", ";
  }

  // member: minerals
  {
    if (msg.minerals.size() == 0) {
      out << "minerals: []";
    } else {
      out << "minerals: [";
      size_t pending_items = msg.minerals.size();
      for (auto item : msg.minerals) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MineralArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: head
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head:\n";
    to_block_style_yaml(msg.head, out, indentation + 2);
  }

  // member: minerals
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.minerals.size() == 0) {
      out << "minerals: []\n";
    } else {
      out << "minerals:\n";
      for (auto item : msg.minerals) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MineralArray & msg, bool use_flow_style = false)
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

}  // namespace mineral_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mineral_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mineral_interfaces::msg::MineralArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  mineral_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mineral_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mineral_interfaces::msg::MineralArray & msg)
{
  return mineral_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mineral_interfaces::msg::MineralArray>()
{
  return "mineral_interfaces::msg::MineralArray";
}

template<>
inline const char * name<mineral_interfaces::msg::MineralArray>()
{
  return "mineral_interfaces/msg/MineralArray";
}

template<>
struct has_fixed_size<mineral_interfaces::msg::MineralArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mineral_interfaces::msg::MineralArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mineral_interfaces::msg::MineralArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__TRAITS_HPP_
