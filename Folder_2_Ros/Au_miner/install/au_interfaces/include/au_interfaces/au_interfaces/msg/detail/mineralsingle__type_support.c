// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from au_interfaces:msg/Mineralsingle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "au_interfaces/msg/detail/mineralsingle__rosidl_typesupport_introspection_c.h"
#include "au_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "au_interfaces/msg/detail/mineralsingle__functions.h"
#include "au_interfaces/msg/detail/mineralsingle__struct.h"


// Include directives for member types
// Member `kind`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  au_interfaces__msg__Mineralsingle__init(message_memory);
}

void au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_fini_function(void * message_memory)
{
  au_interfaces__msg__Mineralsingle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_member_array[4] = {
  {
    "index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__msg__Mineralsingle, index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kind",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__msg__Mineralsingle, kind),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__msg__Mineralsingle, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "price",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(au_interfaces__msg__Mineralsingle, price),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_members = {
  "au_interfaces__msg",  // message namespace
  "Mineralsingle",  // message name
  4,  // number of fields
  sizeof(au_interfaces__msg__Mineralsingle),
  au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_member_array,  // message members
  au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_init_function,  // function to initialize message memory (memory has to be allocated)
  au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_type_support_handle = {
  0,
  &au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_au_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, au_interfaces, msg, Mineralsingle)() {
  au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_type_support_handle.typesupport_identifier) {
    au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &au_interfaces__msg__Mineralsingle__rosidl_typesupport_introspection_c__Mineralsingle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
