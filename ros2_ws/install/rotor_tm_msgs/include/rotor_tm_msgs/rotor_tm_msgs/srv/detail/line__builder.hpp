// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:srv/Line.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__LINE__BUILDER_HPP_
#define ROTOR_TM_MSGS__SRV__DETAIL__LINE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/srv/detail/line__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_Line_Request_path
{
public:
  Init_Line_Request_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rotor_tm_msgs::srv::Line_Request path(::rotor_tm_msgs::srv::Line_Request::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Line_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::Line_Request>()
{
  return rotor_tm_msgs::srv::builder::Init_Line_Request_path();
}

}  // namespace rotor_tm_msgs


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_Line_Response_message
{
public:
  explicit Init_Line_Response_message(::rotor_tm_msgs::srv::Line_Response & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::srv::Line_Response message(::rotor_tm_msgs::srv::Line_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Line_Response msg_;
};

class Init_Line_Response_success
{
public:
  Init_Line_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Line_Response_message success(::rotor_tm_msgs::srv::Line_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Line_Response_message(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Line_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::Line_Response>()
{
  return rotor_tm_msgs::srv::builder::Init_Line_Response_success();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__LINE__BUILDER_HPP_
