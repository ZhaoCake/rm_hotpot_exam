// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mineral_interfaces:msg/Mineral.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL__STRUCT_H_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'kind'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Mineral in the package mineral_interfaces.
typedef struct mineral_interfaces__msg__Mineral
{
  int32_t index;
  rosidl_runtime_c__String kind;
  geometry_msgs__msg__Point position;
  /// double, 64bit float
  double price;
} mineral_interfaces__msg__Mineral;

// Struct for a sequence of mineral_interfaces__msg__Mineral.
typedef struct mineral_interfaces__msg__Mineral__Sequence
{
  mineral_interfaces__msg__Mineral * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mineral_interfaces__msg__Mineral__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL__STRUCT_H_
