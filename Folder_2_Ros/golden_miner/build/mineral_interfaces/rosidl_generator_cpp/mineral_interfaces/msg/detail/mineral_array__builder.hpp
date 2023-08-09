// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mineral_interfaces:msg/MineralArray.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__BUILDER_HPP_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mineral_interfaces/msg/detail/mineral_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mineral_interfaces
{

namespace msg
{

namespace builder
{

class Init_MineralArray_minerals
{
public:
  explicit Init_MineralArray_minerals(::mineral_interfaces::msg::MineralArray & msg)
  : msg_(msg)
  {}
  ::mineral_interfaces::msg::MineralArray minerals(::mineral_interfaces::msg::MineralArray::_minerals_type arg)
  {
    msg_.minerals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mineral_interfaces::msg::MineralArray msg_;
};

class Init_MineralArray_head
{
public:
  Init_MineralArray_head()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MineralArray_minerals head(::mineral_interfaces::msg::MineralArray::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_MineralArray_minerals(msg_);
  }

private:
  ::mineral_interfaces::msg::MineralArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mineral_interfaces::msg::MineralArray>()
{
  return mineral_interfaces::msg::builder::Init_MineralArray_head();
}

}  // namespace mineral_interfaces

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__BUILDER_HPP_
