// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from au_interfaces:action/Mineral.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
#include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "au_interfaces/action/detail/mineral__functions.h"
#include "au_interfaces/action/detail/mineral__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_Goal__init(message_memory);
}

void au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_member_array[1] = {
  {
    "index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_Goal, index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_Goal",  // message name
  1,  // number of fields
  sizeof(au_interfaces__action__Mineral_Goal),
  au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_member_array,  // message members
  au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_Goal)() {
  if (!au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_Goal__rosidl_typesupport_introspection_c__Mineral_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_Result__init(message_memory);
}

void au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_member_array[2] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_Result, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "price_all",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_Result, price_all),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_Result",  // message name
  2,  // number of fields
  sizeof(au_interfaces__action__Mineral_Result),
  au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_member_array,  // message members
  au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_Result)() {
  au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_Result__rosidl_typesupport_introspection_c__Mineral_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `head`
#include "std_msgs/msg/header.h"
// Member `head`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `minerals`
#include "au_interfaces/msg/mineralsingle.h"
// Member `minerals`
#include "au_interfaces/msg/detail/mineralsingle__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_Feedback__init(message_memory);
}

void au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_Feedback__fini(message_memory);
}

size_t au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__size_function__Mineral_Feedback__minerals(
  const void * untyped_member)
{
  const au_interfaces__msg__Mineralsingle__Sequence * member =
    (const au_interfaces__msg__Mineralsingle__Sequence *)(untyped_member);
  return member->size;
}

const void * au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__get_const_function__Mineral_Feedback__minerals(
  const void * untyped_member, size_t index)
{
  const au_interfaces__msg__Mineralsingle__Sequence * member =
    (const au_interfaces__msg__Mineralsingle__Sequence *)(untyped_member);
  return &member->data[index];
}

void * au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__get_function__Mineral_Feedback__minerals(
  void * untyped_member, size_t index)
{
  au_interfaces__msg__Mineralsingle__Sequence * member =
    (au_interfaces__msg__Mineralsingle__Sequence *)(untyped_member);
  return &member->data[index];
}

void au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__fetch_function__Mineral_Feedback__minerals(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const au_interfaces__msg__Mineralsingle * item =
    ((const au_interfaces__msg__Mineralsingle *)
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__get_const_function__Mineral_Feedback__minerals(untyped_member, index));
  au_interfaces__msg__Mineralsingle * value =
    (au_interfaces__msg__Mineralsingle *)(untyped_value);
  *value = *item;
}

void au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__assign_function__Mineral_Feedback__minerals(
  void * untyped_member, size_t index, const void * untyped_value)
{
  au_interfaces__msg__Mineralsingle * item =
    ((au_interfaces__msg__Mineralsingle *)
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__get_function__Mineral_Feedback__minerals(untyped_member, index));
  const au_interfaces__msg__Mineralsingle * value =
    (const au_interfaces__msg__Mineralsingle *)(untyped_value);
  *item = *value;
}

bool au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__resize_function__Mineral_Feedback__minerals(
  void * untyped_member, size_t size)
{
  au_interfaces__msg__Mineralsingle__Sequence * member =
    (au_interfaces__msg__Mineralsingle__Sequence *)(untyped_member);
  au_interfaces__msg__Mineralsingle__Sequence__fini(member);
  return au_interfaces__msg__Mineralsingle__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_member_array[2] = {
  {
    "head",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_Feedback, head),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "minerals",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_Feedback, minerals),  // bytes offset in struct
    NULL,  // default value
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__size_function__Mineral_Feedback__minerals,  // size() function pointer
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__get_const_function__Mineral_Feedback__minerals,  // get_const(index) function pointer
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__get_function__Mineral_Feedback__minerals,  // get(index) function pointer
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__fetch_function__Mineral_Feedback__minerals,  // fetch(index, &value) function pointer
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__assign_function__Mineral_Feedback__minerals,  // assign(index, value) function pointer
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__resize_function__Mineral_Feedback__minerals  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_Feedback",  // message name
  2,  // number of fields
  sizeof(au_interfaces__action__Mineral_Feedback),
  au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_member_array,  // message members
  au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_Feedback)() {
  au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, msg, Mineralsingle)();
  if (!au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_Feedback__rosidl_typesupport_introspection_c__Mineral_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "au_interfaces/action/mineral.h"
// Member `goal`
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_SendGoal_Request__init(message_memory);
}

void au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(au_interfaces__action__Mineral_SendGoal_Request),
  au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_member_array,  // message members
  au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal_Request)() {
  au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_Goal)();
  if (!au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_SendGoal_Request__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_SendGoal_Response__init(message_memory);
}

void au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(au_interfaces__action__Mineral_SendGoal_Response),
  au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_member_array,  // message members
  au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal_Response)() {
  au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_SendGoal_Response__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_members = {
  "au_interfaces__action",  // service namespace
  "Mineral_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_type_support_handle = {
  0,
  &au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal)() {
  if (!au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_type_support_handle.typesupport_identifier) {
    au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_SendGoal_Response)()->data;
  }

  return &au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_GetResult_Request__init(message_memory);
}

void au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(au_interfaces__action__Mineral_GetResult_Request),
  au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_member_array,  // message members
  au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult_Request)() {
  au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_GetResult_Request__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "au_interfaces/action/mineral.h"
// Member `result`
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_GetResult_Response__init(message_memory);
}

void au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(au_interfaces__action__Mineral_GetResult_Response),
  au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_member_array,  // message members
  au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult_Response)() {
  au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_Result)();
  if (!au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_GetResult_Response__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_members = {
  "au_interfaces__action",  // service namespace
  "Mineral_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_type_support_handle = {
  0,
  &au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult)() {
  if (!au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_type_support_handle.typesupport_identifier) {
    au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_GetResult_Response)()->data;
  }

  return &au_interfaces__action__detail__mineral__rosidl_typesupport_introspection_c__Mineral_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"
// already included above
// #include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "au_interfaces/action/detail/mineral__functions.h"
// already included above
// #include "au_interfaces/action/detail/mineral__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "au_interfaces/action/mineral.h"
// Member `feedback`
// already included above
// #include "au_interfaces/action/detail/mineral__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__action__Mineral_FeedbackMessage__init(message_memory);
}

void au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_fini_function(void * message_memory)
{
  au_interfaces__action__Mineral_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__action__Mineral_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_members = {
  "au_interfaces__action",  // message namespace
  "Mineral_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(au_interfaces__action__Mineral_FeedbackMessage),
  au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_member_array,  // message members
  au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_type_support_handle = {
  0,
  &au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_FeedbackMessage)() {
  au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, action, Mineral_Feedback)();
  if (!au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__action__Mineral_FeedbackMessage__rosidl_typesupport_introspection_c__Mineral_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
