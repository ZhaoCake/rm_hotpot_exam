// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__STRUCT_H_
#define AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__STRUCT_H_

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

/// Struct defined in msg/Mineralsingle in the package au_interfaces.
typedef struct au_interfaces__msg__Mineralsingle
{
  int32_t index;
  rosidl_runtime_c__String kind;
  geometry_msgs__msg__Point position;
  double price;
} au_interfaces__msg__Mineralsingle;

// Struct for a sequence of au_interfaces__msg__Mineralsingle.
typedef struct au_interfaces__msg__Mineralsingle__Sequence
{
  au_interfaces__msg__Mineralsingle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__msg__Mineralsingle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__STRUCT_H_
