// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from au_interfaces:action/Mineral.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__ACTION__DETAIL__MINERAL__TRAITS_HPP_
#define AU_INTERFACES__ACTION__DETAIL__MINERAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "au_interfaces/action/detail/mineral__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_Goal & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_Goal>()
{
  return "au_interfaces::action::Mineral_Goal";
}

template<>
inline const char * name<au_interfaces::action::Mineral_Goal>()
{
  return "au_interfaces/action/Mineral_Goal";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<au_interfaces::action::Mineral_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: price_all
  {
    out << "price_all: ";
    rosidl_generator_traits::value_to_yaml(msg.price_all, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: price_all
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "price_all: ";
    rosidl_generator_traits::value_to_yaml(msg.price_all, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_Result & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_Result>()
{
  return "au_interfaces::action::Mineral_Result";
}

template<>
inline const char * name<au_interfaces::action::Mineral_Result>()
{
  return "au_interfaces/action/Mineral_Result";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_Result>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_Result>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<au_interfaces::action::Mineral_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'head'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'minerals'
#include "au_interfaces/msg/detail/mineralsingle__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: head
  {
    out << "head: ";
    to_flow_style_yaml(msg.head, out);
    out << ", ";
  }

  // member: minerals
  {
    if (msg.minerals.size() == 0) {
      out << "minerals: []";
    } else {
      out << "minerals: [";
      size_t pending_items = msg.minerals.size();
      for (auto item : msg.minerals) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: head
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "head:\n";
    to_block_style_yaml(msg.head, out, indentation + 2);
  }

  // member: minerals
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.minerals.size() == 0) {
      out << "minerals: []\n";
    } else {
      out << "minerals:\n";
      for (auto item : msg.minerals) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_Feedback & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_Feedback>()
{
  return "au_interfaces::action::Mineral_Feedback";
}

template<>
inline const char * name<au_interfaces::action::Mineral_Feedback>()
{
  return "au_interfaces/action/Mineral_Feedback";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<au_interfaces::action::Mineral_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "au_interfaces/action/detail/mineral__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_SendGoal_Request & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_SendGoal_Request>()
{
  return "au_interfaces::action::Mineral_SendGoal_Request";
}

template<>
inline const char * name<au_interfaces::action::Mineral_SendGoal_Request>()
{
  return "au_interfaces/action/Mineral_SendGoal_Request";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<au_interfaces::action::Mineral_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<au_interfaces::action::Mineral_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<au_interfaces::action::Mineral_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_SendGoal_Response & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_SendGoal_Response>()
{
  return "au_interfaces::action::Mineral_SendGoal_Response";
}

template<>
inline const char * name<au_interfaces::action::Mineral_SendGoal_Response>()
{
  return "au_interfaces/action/Mineral_SendGoal_Response";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<au_interfaces::action::Mineral_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<au_interfaces::action::Mineral_SendGoal>()
{
  return "au_interfaces::action::Mineral_SendGoal";
}

template<>
inline const char * name<au_interfaces::action::Mineral_SendGoal>()
{
  return "au_interfaces/action/Mineral_SendGoal";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<au_interfaces::action::Mineral_SendGoal_Request>::value &&
    has_fixed_size<au_interfaces::action::Mineral_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<au_interfaces::action::Mineral_SendGoal_Request>::value &&
    has_bounded_size<au_interfaces::action::Mineral_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<au_interfaces::action::Mineral_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<au_interfaces::action::Mineral_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<au_interfaces::action::Mineral_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_GetResult_Request & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_GetResult_Request>()
{
  return "au_interfaces::action::Mineral_GetResult_Request";
}

template<>
inline const char * name<au_interfaces::action::Mineral_GetResult_Request>()
{
  return "au_interfaces/action/Mineral_GetResult_Request";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<au_interfaces::action::Mineral_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "au_interfaces/action/detail/mineral__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_GetResult_Response & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_GetResult_Response>()
{
  return "au_interfaces::action::Mineral_GetResult_Response";
}

template<>
inline const char * name<au_interfaces::action::Mineral_GetResult_Response>()
{
  return "au_interfaces/action/Mineral_GetResult_Response";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<au_interfaces::action::Mineral_Result>::value> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<au_interfaces::action::Mineral_Result>::value> {};

template<>
struct is_message<au_interfaces::action::Mineral_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<au_interfaces::action::Mineral_GetResult>()
{
  return "au_interfaces::action::Mineral_GetResult";
}

template<>
inline const char * name<au_interfaces::action::Mineral_GetResult>()
{
  return "au_interfaces/action/Mineral_GetResult";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<au_interfaces::action::Mineral_GetResult_Request>::value &&
    has_fixed_size<au_interfaces::action::Mineral_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<au_interfaces::action::Mineral_GetResult_Request>::value &&
    has_bounded_size<au_interfaces::action::Mineral_GetResult_Response>::value
  >
{
};

template<>
struct is_service<au_interfaces::action::Mineral_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<au_interfaces::action::Mineral_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<au_interfaces::action::Mineral_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "au_interfaces/action/detail/mineral__traits.hpp"

namespace au_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Mineral_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mineral_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mineral_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace au_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use au_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const au_interfaces::action::Mineral_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  au_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use au_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const au_interfaces::action::Mineral_FeedbackMessage & msg)
{
  return au_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<au_interfaces::action::Mineral_FeedbackMessage>()
{
  return "au_interfaces::action::Mineral_FeedbackMessage";
}

template<>
inline const char * name<au_interfaces::action::Mineral_FeedbackMessage>()
{
  return "au_interfaces/action/Mineral_FeedbackMessage";
}

template<>
struct has_fixed_size<au_interfaces::action::Mineral_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<au_interfaces::action::Mineral_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<au_interfaces::action::Mineral_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<au_interfaces::action::Mineral_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<au_interfaces::action::Mineral_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<au_interfaces::action::Mineral>
  : std::true_type
{
};

template<>
struct is_action_goal<au_interfaces::action::Mineral_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<au_interfaces::action::Mineral_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<au_interfaces::action::Mineral_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // AU_INTERFACES__ACTION__DETAIL__MINERAL__TRAITS_HPP_
