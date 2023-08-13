// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__FUNCTIONS_H_
#define AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "au_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "au_interfaces/msg/detail/mineralsingle__struct.h"

/// Initialize msg/Mineralsingle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * au_interfaces__msg__Mineralsingle
 * )) before or use
 * au_interfaces__msg__Mineralsingle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
bool
au_interfaces__msg__Mineralsingle__init(au_interfaces__msg__Mineralsingle * msg);

/// Finalize msg/Mineralsingle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
void
au_interfaces__msg__Mineralsingle__fini(au_interfaces__msg__Mineralsingle * msg);

/// Create msg/Mineralsingle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * au_interfaces__msg__Mineralsingle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
au_interfaces__msg__Mineralsingle *
au_interfaces__msg__Mineralsingle__create();

/// Destroy msg/Mineralsingle message.
/**
 * It calls
 * au_interfaces__msg__Mineralsingle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
void
au_interfaces__msg__Mineralsingle__destroy(au_interfaces__msg__Mineralsingle * msg);

/// Check for msg/Mineralsingle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
bool
au_interfaces__msg__Mineralsingle__are_equal(const au_interfaces__msg__Mineralsingle * lhs, const au_interfaces__msg__Mineralsingle * rhs);

/// Copy a msg/Mineralsingle message.
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
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
bool
au_interfaces__msg__Mineralsingle__copy(
  const au_interfaces__msg__Mineralsingle * input,
  au_interfaces__msg__Mineralsingle * output);

/// Initialize array of msg/Mineralsingle messages.
/**
 * It allocates the memory for the number of elements and calls
 * au_interfaces__msg__Mineralsingle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
bool
au_interfaces__msg__Mineralsingle__Sequence__init(au_interfaces__msg__Mineralsingle__Sequence * array, size_t size);

/// Finalize array of msg/Mineralsingle messages.
/**
 * It calls
 * au_interfaces__msg__Mineralsingle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
void
au_interfaces__msg__Mineralsingle__Sequence__fini(au_interfaces__msg__Mineralsingle__Sequence * array);

/// Create array of msg/Mineralsingle messages.
/**
 * It allocates the memory for the array and calls
 * au_interfaces__msg__Mineralsingle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
au_interfaces__msg__Mineralsingle__Sequence *
au_interfaces__msg__Mineralsingle__Sequence__create(size_t size);

/// Destroy array of msg/Mineralsingle messages.
/**
 * It calls
 * au_interfaces__msg__Mineralsingle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
void
au_interfaces__msg__Mineralsingle__Sequence__destroy(au_interfaces__msg__Mineralsingle__Sequence * array);

/// Check for msg/Mineralsingle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
bool
au_interfaces__msg__Mineralsingle__Sequence__are_equal(const au_interfaces__msg__Mineralsingle__Sequence * lhs, const au_interfaces__msg__Mineralsingle__Sequence * rhs);

/// Copy an array of msg/Mineralsingle messages.
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
ROSIDL_GENERATOR_C_PUBLIC_au_interfaces
bool
au_interfaces__msg__Mineralsingle__Sequence__copy(
  const au_interfaces__msg__Mineralsingle__Sequence * input,
  au_interfaces__msg__Mineralsingle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AU_INTERFACES__MSG__DETAIL__MINERALSINGLE__FUNCTIONS_H_
