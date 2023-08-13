// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from au_interfaces:action/Mineral.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__ACTION__DETAIL__MINERAL__STRUCT_H_
#define AU_INTERFACES__ACTION__DETAIL__MINERAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_Goal
{
  int32_t index;
} au_interfaces__action__Mineral_Goal;

// Struct for a sequence of au_interfaces__action__Mineral_Goal.
typedef struct au_interfaces__action__Mineral_Goal__Sequence
{
  au_interfaces__action__Mineral_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_Result
{
  geometry_msgs__msg__Point position;
  double price_all;
} au_interfaces__action__Mineral_Result;

// Struct for a sequence of au_interfaces__action__Mineral_Result.
typedef struct au_interfaces__action__Mineral_Result__Sequence
{
  au_interfaces__action__Mineral_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'head'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'minerals'
#include "au_interfaces/msg/detail/mineralsingle__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_Feedback
{
  std_msgs__msg__Header head;
  au_interfaces__msg__Mineralsingle__Sequence minerals;
} au_interfaces__action__Mineral_Feedback;

// Struct for a sequence of au_interfaces__action__Mineral_Feedback.
typedef struct au_interfaces__action__Mineral_Feedback__Sequence
{
  au_interfaces__action__Mineral_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "au_interfaces/action/detail/mineral__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  au_interfaces__action__Mineral_Goal goal;
} au_interfaces__action__Mineral_SendGoal_Request;

// Struct for a sequence of au_interfaces__action__Mineral_SendGoal_Request.
typedef struct au_interfaces__action__Mineral_SendGoal_Request__Sequence
{
  au_interfaces__action__Mineral_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} au_interfaces__action__Mineral_SendGoal_Response;

// Struct for a sequence of au_interfaces__action__Mineral_SendGoal_Response.
typedef struct au_interfaces__action__Mineral_SendGoal_Response__Sequence
{
  au_interfaces__action__Mineral_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} au_interfaces__action__Mineral_GetResult_Request;

// Struct for a sequence of au_interfaces__action__Mineral_GetResult_Request.
typedef struct au_interfaces__action__Mineral_GetResult_Request__Sequence
{
  au_interfaces__action__Mineral_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_GetResult_Response
{
  int8_t status;
  au_interfaces__action__Mineral_Result result;
} au_interfaces__action__Mineral_GetResult_Response;

// Struct for a sequence of au_interfaces__action__Mineral_GetResult_Response.
typedef struct au_interfaces__action__Mineral_GetResult_Response__Sequence
{
  au_interfaces__action__Mineral_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"

/// Struct defined in action/Mineral in the package au_interfaces.
typedef struct au_interfaces__action__Mineral_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  au_interfaces__action__Mineral_Feedback feedback;
} au_interfaces__action__Mineral_FeedbackMessage;

// Struct for a sequence of au_interfaces__action__Mineral_FeedbackMessage.
typedef struct au_interfaces__action__Mineral_FeedbackMessage__Sequence
{
  au_interfaces__action__Mineral_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} au_interfaces__action__Mineral_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AU_INTERFACES__ACTION__DETAIL__MINERAL__STRUCT_H_
