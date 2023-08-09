// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mineral_interfaces:msg/Mineral.idl
// generated code does not contain a copyright notice

#ifndef MINERAL_INTERFACES__MSG__DETAIL__MINERAL__FUNCTIONS_H_
#define MINERAL_INTERFACES__MSG__DETAIL__MINERAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mineral_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mineral_interfaces/msg/detail/mineral__struct.h"

/// Initialize msg/Mineral message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mineral_interfaces__msg__Mineral
 * )) before or use
 * mineral_interfaces__msg__Mineral__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
bool
mineral_interfaces__msg__Mineral__init(mineral_interfaces__msg__Mineral * msg);

/// Finalize msg/Mineral message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
void
mineral_interfaces__msg__Mineral__fini(mineral_interfaces__msg__Mineral * msg);

/// Create msg/Mineral message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mineral_interfaces__msg__Mineral__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
mineral_interfaces__msg__Mineral *
mineral_interfaces__msg__Mineral__create();

/// Destroy msg/Mineral message.
/**
 * It calls
 * mineral_interfaces__msg__Mineral__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
void
mineral_interfaces__msg__Mineral__destroy(mineral_interfaces__msg__Mineral * msg);

/// Check for msg/Mineral message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
bool
mineral_interfaces__msg__Mineral__are_equal(const mineral_interfaces__msg__Mineral * lhs, const mineral_interfaces__msg__Mineral * rhs);

/// Copy a msg/Mineral message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
bool
mineral_interfaces__msg__Mineral__copy(
  const mineral_interfaces__msg__Mineral * input,
  mineral_interfaces__msg__Mineral * output);

/// Initialize array of msg/Mineral messages.
/**
 * It allocates the memory for the number of elements and calls
 * mineral_interfaces__msg__Mineral__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
bool
mineral_interfaces__msg__Mineral__Sequence__init(mineral_interfaces__msg__Mineral__Sequence * array, size_t size);

/// Finalize array of msg/Mineral messages.
/**
 * It calls
 * mineral_interfaces__msg__Mineral__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
void
mineral_interfaces__msg__Mineral__Sequence__fini(mineral_interfaces__msg__Mineral__Sequence * array);

/// Create array of msg/Mineral messages.
/**
 * It allocates the memory for the array and calls
 * mineral_interfaces__msg__Mineral__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
mineral_interfaces__msg__Mineral__Sequence *
mineral_interfaces__msg__Mineral__Sequence__create(size_t size);

/// Destroy array of msg/Mineral messages.
/**
 * It calls
 * mineral_interfaces__msg__Mineral__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
void
mineral_interfaces__msg__Mineral__Sequence__destroy(mineral_interfaces__msg__Mineral__Sequence * array);

/// Check for msg/Mineral message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
bool
mineral_interfaces__msg__Mineral__Sequence__are_equal(const mineral_interfaces__msg__Mineral__Sequence * lhs, const mineral_interfaces__msg__Mineral__Sequence * rhs);

/// Copy an array of msg/Mineral messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mineral_interfaces
bool
mineral_interfaces__msg__Mineral__Sequence__copy(
  const mineral_interfaces__msg__Mineral__Sequence * input,
  mineral_interfaces__msg__Mineral__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MINERAL_INTERFACES__MSG__DETAIL__MINERAL__FUNCTIONS_H_
