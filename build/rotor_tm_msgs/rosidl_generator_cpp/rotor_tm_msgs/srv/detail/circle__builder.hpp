// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:srv/Circle.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__CIRCLE__BUILDER_HPP_
#define ROTOR_TM_MSGS__SRV__DETAIL__CIRCLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/srv/detail/circle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_Circle_Request_duration
{
public:
  explicit Init_Circle_Request_duration(::rotor_tm_msgs::srv::Circle_Request & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::srv::Circle_Request duration(::rotor_tm_msgs::srv::Circle_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Circle_Request msg_;
};

class Init_Circle_Request_tp
{
public:
  explicit Init_Circle_Request_tp(::rotor_tm_msgs::srv::Circle_Request & msg)
  : msg_(msg)
  {}
  Init_Circle_Request_duration tp(::rotor_tm_msgs::srv::Circle_Request::_tp_type arg)
  {
    msg_.tp = std::move(arg);
    return Init_Circle_Request_duration(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Circle_Request msg_;
};

class Init_Circle_Request_radius
{
public:
  Init_Circle_Request_radius()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Circle_Request_tp radius(::rotor_tm_msgs::srv::Circle_Request::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_Circle_Request_tp(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Circle_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::Circle_Request>()
{
  return rotor_tm_msgs::srv::builder::Init_Circle_Request_radius();
}

}  // namespace rotor_tm_msgs


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_Circle_Response_message
{
public:
  explicit Init_Circle_Response_message(::rotor_tm_msgs::srv::Circle_Response & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::srv::Circle_Response message(::rotor_tm_msgs::srv::Circle_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Circle_Response msg_;
};

class Init_Circle_Response_success
{
public:
  Init_Circle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Circle_Response_message success(::rotor_tm_msgs::srv::Circle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Circle_Response_message(msg_);
  }

private:
  ::rotor_tm_msgs::srv::Circle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::Circle_Response>()
{
  return rotor_tm_msgs::srv::builder::Init_Circle_Response_success();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__CIRCLE__BUILDER_HPP_
