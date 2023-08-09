// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mineral_interfaces:msg/Mineral.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL__STRUCT_HPP_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mineral_interfaces__msg__Mineral __attribute__((deprecated))
#else
# define DEPRECATED__mineral_interfaces__msg__Mineral __declspec(deprecated)
#endif

namespace mineral_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Mineral_
{
  using Type = Mineral_<ContainerAllocator>;

  explicit Mineral_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0l;
      this->kind = "";
      this->price = 0.0;
    }
  }

  explicit Mineral_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : kind(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0l;
      this->kind = "";
      this->price = 0.0;
    }
  }

  // field types and members
  using _index_type =
    int32_t;
  _index_type index;
  using _kind_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _kind_type kind;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _price_type =
    double;
  _price_type price;

  // setters for named parameter idiom
  Type & set__index(
    const int32_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__kind(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->kind = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__price(
    const double & _arg)
  {
    this->price = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mineral_interfaces::msg::Mineral_<ContainerAllocator> *;
  using ConstRawPtr =
    const mineral_interfaces::msg::Mineral_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mineral_interfaces::msg::Mineral_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mineral_interfaces::msg::Mineral_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mineral_interfaces__msg__Mineral
    std::shared_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mineral_interfaces__msg__Mineral
    std::shared_ptr<mineral_interfaces::msg::Mineral_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mineral_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->kind != other.kind) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->price != other.price) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mineral_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mineral_

// alias to use template instance with default allocator
using Mineral =
  mineral_interfaces::msg::Mineral_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mineral_interfaces

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL__STRUCT_HPP_
