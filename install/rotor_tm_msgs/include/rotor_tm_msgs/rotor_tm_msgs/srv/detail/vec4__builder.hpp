// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:srv/Vec4.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__VEC4__BUILDER_HPP_
#define ROTOR_TM_MSGS__SRV__DETAIL__VEC4__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/srv/detail/vec4__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_Vec4_Request_goal
{
public:
  Init_Vec4_Request_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rotor_tm_msgs::srv::Vec4_Request goal(::rotor_tm_msgs::srv::Vec4_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Vec4_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::Vec4_Request>()
{
  return rotor_tm_msgs::srv::builder::Init_Vec4_Request_goal();
}

}  // namespace rotor_tm_msgs


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_Vec4_Response_message
{
public:
  explicit Init_Vec4_Response_message(::rotor_tm_msgs::srv::Vec4_Response & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::srv::Vec4_Response message(::rotor_tm_msgs::srv::Vec4_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Vec4_Response msg_;
};

class Init_Vec4_Response_success
{
public:
  Init_Vec4_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Vec4_Response_message success(::rotor_tm_msgs::srv::Vec4_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Vec4_Response_message(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Vec4_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::Vec4_Response>()
{
  return rotor_tm_msgs::srv::builder::Init_Vec4_Response_success();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__VEC4__BUILDER_HPP_
