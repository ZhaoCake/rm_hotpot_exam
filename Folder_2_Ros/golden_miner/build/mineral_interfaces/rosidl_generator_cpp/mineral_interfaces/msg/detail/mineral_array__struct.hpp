// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mineral_interfaces:msg/MineralArray.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__STRUCT_HPP_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'head'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'minerals'
#include "mineral_interfaces/msg/detail/mineral__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mineral_interfaces__msg__MineralArray __attribute__((deprecated))
#else
# define DEPRECATED__mineral_interfaces__msg__MineralArray __declspec(deprecated)
#endif

namespace mineral_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MineralArray_
{
  using Type = MineralArray_<ContainerAllocator>;

  explicit MineralArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : head(_init)
  {
    (void)_init;
  }

  explicit MineralArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : head(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _head_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _head_type head;
  using _minerals_type =
    std::vector<mineral_interfaces::msg::Mineral_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mineral_interfaces::msg::Mineral_<ContainerAllocator>>>;
  _minerals_type minerals;

  // setters for named parameter idiom
  Type & set__head(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->head = _arg;
    return *this;
  }
  Type & set__minerals(
    const std::vector<mineral_interfaces::msg::Mineral_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mineral_interfaces::msg::Mineral_<ContainerAllocator>>> & _arg)
  {
    this->minerals = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mineral_interfaces::msg::MineralArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const mineral_interfaces::msg::MineralArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mineral_interfaces::msg::MineralArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mineral_interfaces::msg::MineralArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mineral_interfaces__msg__MineralArray
    std::shared_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mineral_interfaces__msg__MineralArray
    std::shared_ptr<mineral_interfaces::msg::MineralArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MineralArray_ & other) const
  {
    if (this->head != other.head) {
      return false;
    }
    if (this->minerals != other.minerals) {
      return false;
    }
    return true;
  }
  bool operator!=(const MineralArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MineralArray_

// alias to use template instance with default allocator
using MineralArray =
  mineral_interfaces::msg::MineralArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mineral_interfaces

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__STRUCT_HPP_
