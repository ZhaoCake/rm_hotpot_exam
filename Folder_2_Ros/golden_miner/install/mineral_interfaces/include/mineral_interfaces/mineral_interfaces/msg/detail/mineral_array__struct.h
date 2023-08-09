// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mineral_interfaces:msg/MineralArray.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__STRUCT_H_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'head'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'minerals'
#include "mineral_interfaces/msg/detail/mineral__struct.h"

/// Struct defined in msg/MineralArray in the package mineral_interfaces.
typedef struct mineral_interfaces__msg__MineralArray
{
  std_msgs__msg__Header head;
  mineral_interfaces__msg__Mineral__Sequence minerals;
} mineral_interfaces__msg__MineralArray;

// Struct for a sequence of mineral_interfaces__msg__MineralArray.
typedef struct mineral_interfaces__msg__MineralArray__Sequence
{
  mineral_interfaces__msg__MineralArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mineral_interfaces__msg__MineralArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL_ARRAY__STRUCT_H_
