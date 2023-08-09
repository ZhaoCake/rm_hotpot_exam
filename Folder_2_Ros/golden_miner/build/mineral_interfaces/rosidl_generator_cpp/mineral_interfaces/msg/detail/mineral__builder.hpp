// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mineral_interfaces:msg/Mineral.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL__BUILDER_HPP_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mineral_interfaces/msg/detail/mineral__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mineral_interfaces
{

namespace msg
{

namespace builder
{

class Init_Mineral_price
{
public:
  explicit Init_Mineral_price(::mineral_interfaces::msg::Mineral & msg)
  : msg_(msg)
  {}
  ::mineral_interfaces::msg::Mineral price(::mineral_interfaces::msg::Mineral::_price_type arg)
  {
    msg_.price = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mineral_interfaces::msg::Mineral msg_;
};

class Init_Mineral_position
{
public:
  explicit Init_Mineral_position(::mineral_interfaces::msg::Mineral & msg)
  : msg_(msg)
  {}
  Init_Mineral_price position(::mineral_interfaces::msg::Mineral::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Mineral_price(msg_);
  }

private:
  ::mineral_interfaces::msg::Mineral msg_;
};

class Init_Mineral_kind
{
public:
  explicit Init_Mineral_kind(::mineral_interfaces::msg::Mineral & msg)
  : msg_(msg)
  {}
  Init_Mineral_position kind(::mineral_interfaces::msg::Mineral::_kind_type arg)
  {
    msg_.kind = std::move(arg);
    return Init_Mineral_position(msg_);
  }

private:
  ::mineral_interfaces::msg::Mineral msg_;
};

class Init_Mineral_index
{
public:
  Init_Mineral_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_kind index(::mineral_interfaces::msg::Mineral::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_Mineral_kind(msg_);
  }

private:
  ::mineral_interfaces::msg::Mineral msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mineral_interfaces::msg::Mineral>()
{
  return mineral_interfaces::msg::builder::Init_Mineral_index();
}

}  // namespace mineral_interfaces

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL__BUILDER_HPP_
