// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice
#include "au_interfaces/msg/detail/mineralsingle__functions.h"

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
au_interfaces__msg__Mineralsingle__init(au_interfaces__msg__Mineralsingle * msg)
{
  if (!msg) {
    return false;
  }
  // index
  // kind
  if (!rosidl_runtime_c__String__init(&msg->kind)) {
    au_interfaces__msg__Mineralsingle__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    au_interfaces__msg__Mineralsingle__fini(msg);
    return false;
  }
  // price
  return true;
}

void
au_interfaces__msg__Mineralsingle__fini(au_interfaces__msg__Mineralsingle * msg)
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
au_interfaces__msg__Mineralsingle__are_equal(const au_interfaces__msg__Mineralsingle * lhs, const au_interfaces__msg__Mineralsingle * rhs)
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
au_interfaces__msg__Mineralsingle__copy(
  const au_interfaces__msg__Mineralsingle * input,
  au_interfaces__msg__Mineralsingle * output)
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

au_interfaces__msg__Mineralsingle *
au_interfaces__msg__Mineralsingle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  au_interfaces__msg__Mineralsingle * msg = (au_interfaces__msg__Mineralsingle *)allocator.allocate(sizeof(au_interfaces__msg__Mineralsingle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(au_interfaces__msg__Mineralsingle));
  bool success = au_interfaces__msg__Mineralsingle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
au_interfaces__msg__Mineralsingle__destroy(au_interfaces__msg__Mineralsingle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    au_interfaces__msg__Mineralsingle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
au_interfaces__msg__Mineralsingle__Sequence__init(au_interfaces__msg__Mineralsingle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  au_interfaces__msg__Mineralsingle * data = NULL;

  if (size) {
    data = (au_interfaces__msg__Mineralsingle *)allocator.zero_allocate(size, sizeof(au_interfaces__msg__Mineralsingle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = au_interfaces__msg__Mineralsingle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        au_interfaces__msg__Mineralsingle__fini(&data[i - 1]);
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
au_interfaces__msg__Mineralsingle__Sequence__fini(au_interfaces__msg__Mineralsingle__Sequence * array)
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
      au_interfaces__msg__Mineralsingle__fini(&array->data[i]);
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

au_interfaces__msg__Mineralsingle__Sequence *
au_interfaces__msg__Mineralsingle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  au_interfaces__msg__Mineralsingle__Sequence * array = (au_interfaces__msg__Mineralsingle__Sequence *)allocator.allocate(sizeof(au_interfaces__msg__Mineralsingle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = au_interfaces__msg__Mineralsingle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
au_interfaces__msg__Mineralsingle__Sequence__destroy(au_interfaces__msg__Mineralsingle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    au_interfaces__msg__Mineralsingle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
au_interfaces__msg__Mineralsingle__Sequence__are_equal(const au_interfaces__msg__Mineralsingle__Sequence * lhs, const au_interfaces__msg__Mineralsingle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!au_interfaces__msg__Mineralsingle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
au_interfaces__msg__Mineralsingle__Sequence__copy(
  const au_interfaces__msg__Mineralsingle__Sequence * input,
  au_interfaces__msg__Mineralsingle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(au_interfaces__msg__Mineralsingle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    au_interfaces__msg__Mineralsingle * data =
      (au_interfaces__msg__Mineralsingle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!au_interfaces__msg__Mineralsingle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          au_interfaces__msg__Mineralsingle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!au_interfaces__msg__Mineralsingle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
