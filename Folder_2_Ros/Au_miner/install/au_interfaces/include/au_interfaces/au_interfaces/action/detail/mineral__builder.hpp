// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from au_interfaces:action/Mineral.idl
// generated code does not contain a copyright notice

#ifndef AU_INTERFACES__ACTION__DETAIL__MINERAL__BUILDER_HPP_
#define AU_INTERFACES__ACTION__DETAIL__MINERAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "au_interfaces/action/detail/mineral__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_Goal_index
{
public:
  Init_Mineral_Goal_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::au_interfaces::action::Mineral_Goal index(::au_interfaces::action::Mineral_Goal::_index_type arg)
  {
    msg_.index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_Goal>()
{
  return au_interfaces::action::builder::Init_Mineral_Goal_index();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_Result_price_all
{
public:
  explicit Init_Mineral_Result_price_all(::au_interfaces::action::Mineral_Result & msg)
  : msg_(msg)
  {}
  ::au_interfaces::action::Mineral_Result price_all(::au_interfaces::action::Mineral_Result::_price_all_type arg)
  {
    msg_.price_all = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_Result msg_;
};

class Init_Mineral_Result_position
{
public:
  Init_Mineral_Result_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_Result_price_all position(::au_interfaces::action::Mineral_Result::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Mineral_Result_price_all(msg_);
  }

private:
  ::au_interfaces::action::Mineral_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_Result>()
{
  return au_interfaces::action::builder::Init_Mineral_Result_position();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_Feedback_minerals
{
public:
  explicit Init_Mineral_Feedback_minerals(::au_interfaces::action::Mineral_Feedback & msg)
  : msg_(msg)
  {}
  ::au_interfaces::action::Mineral_Feedback minerals(::au_interfaces::action::Mineral_Feedback::_minerals_type arg)
  {
    msg_.minerals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_Feedback msg_;
};

class Init_Mineral_Feedback_head
{
public:
  Init_Mineral_Feedback_head()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_Feedback_minerals head(::au_interfaces::action::Mineral_Feedback::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_Mineral_Feedback_minerals(msg_);
  }

private:
  ::au_interfaces::action::Mineral_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_Feedback>()
{
  return au_interfaces::action::builder::Init_Mineral_Feedback_head();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_SendGoal_Request_goal
{
public:
  explicit Init_Mineral_SendGoal_Request_goal(::au_interfaces::action::Mineral_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::au_interfaces::action::Mineral_SendGoal_Request goal(::au_interfaces::action::Mineral_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_SendGoal_Request msg_;
};

class Init_Mineral_SendGoal_Request_goal_id
{
public:
  Init_Mineral_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_SendGoal_Request_goal goal_id(::au_interfaces::action::Mineral_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Mineral_SendGoal_Request_goal(msg_);
  }

private:
  ::au_interfaces::action::Mineral_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_SendGoal_Request>()
{
  return au_interfaces::action::builder::Init_Mineral_SendGoal_Request_goal_id();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_SendGoal_Response_stamp
{
public:
  explicit Init_Mineral_SendGoal_Response_stamp(::au_interfaces::action::Mineral_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::au_interfaces::action::Mineral_SendGoal_Response stamp(::au_interfaces::action::Mineral_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_SendGoal_Response msg_;
};

class Init_Mineral_SendGoal_Response_accepted
{
public:
  Init_Mineral_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_SendGoal_Response_stamp accepted(::au_interfaces::action::Mineral_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Mineral_SendGoal_Response_stamp(msg_);
  }

private:
  ::au_interfaces::action::Mineral_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_SendGoal_Response>()
{
  return au_interfaces::action::builder::Init_Mineral_SendGoal_Response_accepted();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_GetResult_Request_goal_id
{
public:
  Init_Mineral_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::au_interfaces::action::Mineral_GetResult_Request goal_id(::au_interfaces::action::Mineral_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_GetResult_Request>()
{
  return au_interfaces::action::builder::Init_Mineral_GetResult_Request_goal_id();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_GetResult_Response_result
{
public:
  explicit Init_Mineral_GetResult_Response_result(::au_interfaces::action::Mineral_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::au_interfaces::action::Mineral_GetResult_Response result(::au_interfaces::action::Mineral_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_GetResult_Response msg_;
};

class Init_Mineral_GetResult_Response_status
{
public:
  Init_Mineral_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_GetResult_Response_result status(::au_interfaces::action::Mineral_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Mineral_GetResult_Response_result(msg_);
  }

private:
  ::au_interfaces::action::Mineral_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_GetResult_Response>()
{
  return au_interfaces::action::builder::Init_Mineral_GetResult_Response_status();
}

}  // namespace au_interfaces


namespace au_interfaces
{

namespace action
{

namespace builder
{

class Init_Mineral_FeedbackMessage_feedback
{
public:
  explicit Init_Mineral_FeedbackMessage_feedback(::au_interfaces::action::Mineral_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::au_interfaces::action::Mineral_FeedbackMessage feedback(::au_interfaces::action::Mineral_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::au_interfaces::action::Mineral_FeedbackMessage msg_;
};

class Init_Mineral_FeedbackMessage_goal_id
{
public:
  Init_Mineral_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mineral_FeedbackMessage_feedback goal_id(::au_interfaces::action::Mineral_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Mineral_FeedbackMessage_feedback(msg_);
  }

private:
  ::au_interfaces::action::Mineral_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::au_interfaces::action::Mineral_FeedbackMessage>()
{
  return au_interfaces::action::builder::Init_Mineral_FeedbackMessage_goal_id();
}

}  // namespace au_interfaces

#endif  // AU_INTERFACES__ACTION__DETAIL__MINERAL__BUILDER_HPP_
