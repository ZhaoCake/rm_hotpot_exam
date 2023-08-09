// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mineral_interfaces:msg/Mineral.idl
// generated code does not contain a copyright notice
#include "mineral_interfaces/msg/detail/mineral__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `kind`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
mineral_interfaces__msg__Mineral__init(mineral_interfaces__msg__Mineral * msg)
{
  if (!msg) {
    return false;
  }
  // index
  // kind
  if (!rosidl_runtime_c__String__init(&msg->kind)) {
    mineral_interfaces__msg__Mineral__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    mineral_interfaces__msg__Mineral__fini(msg);
    return false;
  }
  // price
  return true;
}

void
mineral_interfaces__msg__Mineral__fini(mineral_interfaces__msg__Mineral * msg)
{
  if (!msg) {
    return;
  }
  // index
  // kind
  rosidl_runtime_c__String__fini(&msg->kind);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // price
}

bool
mineral_interfaces__msg__Mineral__are_equal(const mineral_interfaces__msg__Mineral * lhs, const mineral_interfaces__msg__Mineral * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  // kind
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->kind), &(rhs->kind)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // price
  if (lhs->price != rhs->price) {
    return false;
  }
  return true;
}

bool
mineral_interfaces__msg__Mineral__copy(
  const mineral_interfaces__msg__Mineral * input,
  mineral_interfaces__msg__Mineral * output)
{
  if (!input || !output) {
    return false;
  }
  // index
  output->index = input->index;
  // kind
  if (!rosidl_runtime_c__String__copy(
      &(input->kind), &(output->kind)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // price
  output->price = input->price;
  return true;
}

mineral_interfaces__msg__Mineral *
mineral_interfaces__msg__Mineral__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mineral_interfaces__msg__Mineral * msg = (mineral_interfaces__msg__Mineral *)allocator.allocate(sizeof(mineral_interfaces__msg__Mineral), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mineral_interfaces__msg__Mineral));
  bool success = mineral_interfaces__msg__Mineral__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mineral_interfaces__msg__Mineral__destroy(mineral_interfaces__msg__Mineral * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mineral_interfaces__msg__Mineral__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mineral_interfaces__msg__Mineral__Sequence__init(mineral_interfaces__msg__Mineral__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mineral_interfaces__msg__Mineral * data = NULL;

  if (size) {
    data = (mineral_interfaces__msg__Mineral *)allocator.zero_allocate(size, sizeof(mineral_interfaces__msg__Mineral), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mineral_interfaces__msg__Mineral__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mineral_interfaces__msg__Mineral__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mineral_interfaces__msg__Mineral__Sequence__fini(mineral_interfaces__msg__Mineral__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mineral_interfaces__msg__Mineral__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mineral_interfaces__msg__Mineral__Sequence *
mineral_interfaces__msg__Mineral__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mineral_interfaces__msg__Mineral__Sequence * array = (mineral_interfaces__msg__Mineral__Sequence *)allocator.allocate(sizeof(mineral_interfaces__msg__Mineral__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mineral_interfaces__msg__Mineral__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mineral_interfaces__msg__Mineral__Sequence__destroy(mineral_interfaces__msg__Mineral__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mineral_interfaces__msg__Mineral__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mineral_interfaces__msg__Mineral__Sequence__are_equal(const mineral_interfaces__msg__Mineral__Sequence * lhs, const mineral_interfaces__msg__Mineral__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mineral_interfaces__msg__Mineral__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mineral_interfaces__msg__Mineral__Sequence__copy(
  const mineral_interfaces__msg__Mineral__Sequence * input,
  mineral_interfaces__msg__Mineral__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mineral_interfaces__msg__Mineral);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mineral_interfaces__msg__Mineral * data =
      (mineral_interfaces__msg__Mineral *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mineral_interfaces__msg__Mineral__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mineral_interfaces__msg__Mineral__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mineral_interfaces__msg__Mineral__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
