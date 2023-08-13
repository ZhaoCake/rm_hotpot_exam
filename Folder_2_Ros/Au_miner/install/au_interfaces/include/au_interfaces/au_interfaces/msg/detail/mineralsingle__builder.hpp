// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__BUILDER_HPP_
#define AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "au_interfaces/msg/detail/mineralsingle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace au_interfaces
{

namespace msg
{

namespace builder
{

class Init_Mineralsingle_price
{
public:
  explicit Init_Mineralsingle_price(::au_interfaces::msg::Mineralsingle & msg)
  : msg_(msg)
  {}
  ::au_interfaces::msg::Mineralsingle price(::au_interfaces::msg::Mineralsingle::_price_type arg)
  {
    msg_.price = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::msg::Mineralsingle msg_;
};

class Init_Mineralsingle_position
{
public:
  explicit Init_Mineralsingle_position(::au_interfaces::msg::Mineralsingle & msg)
  : msg_(msg)
  {}
  Init_Mineralsingle_price position(::au_interfaces::msg::Mineralsingle::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Mineralsingle_price(msg_);
  }

private:
  ::au_interfaces::msg::Mineralsingle msg_;
};

class Init_Mineralsingle_kind
{
public:
  explicit Init_Mineralsingle_kind(::au_interfaces::msg::Mineralsingle & msg)
  : msg_(msg)
  {}
  Init_Mineralsingle_position kind(::au_interfaces::msg::Mineralsingle::_kind_type arg)
  {
    msg_.kind = std::move(arg);
    return Init_Mineralsingle_position(msg_);
  }

private:
  ::au_interfaces::msg::Mineralsingle msg_;
};

class Init_Mineralsingle_index
{
public:
  Init_Mineralsingle_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineralsingle_kind index(::au_interfaces::msg::Mineralsingle::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_Mineralsingle_kind(msg_);
  }

private:
  ::au_interfaces::msg::Mineralsingle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::msg::Mineralsingle>()
{
  return au_interfaces::msg::builder::Init_Mineralsingle_index();
}

}  // namespace au_interfaces

#endif  // AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__BUILDER_HPP_
