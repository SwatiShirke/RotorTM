// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/FMCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/fm_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_FMCommand_moments
{
public:
  explicit Init_FMCommand_moments(::rotor_tm_msgs::msg::FMCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::FMCommand moments(::rotor_tm_msgs::msg::FMCommand::_moments_type arg)
  {
    msg_.moments = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMCommand msg_;
};

class Init_FMCommand_rlink_thrust
{
public:
  explicit Init_FMCommand_rlink_thrust(::rotor_tm_msgs::msg::FMCommand & msg)
  : msg_(msg)
  {}
  Init_FMCommand_moments rlink_thrust(::rotor_tm_msgs::msg::FMCommand::_rlink_thrust_type arg)
  {
    msg_.rlink_thrust = std::move(arg);
    return Init_FMCommand_moments(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMCommand msg_;
};

class Init_FMCommand_thrust
{
public:
  explicit Init_FMCommand_thrust(::rotor_tm_msgs::msg::FMCommand & msg)
  : msg_(msg)
  {}
  Init_FMCommand_rlink_thrust thrust(::rotor_tm_msgs::msg::FMCommand::_thrust_type arg)
  {
    msg_.thrust = std::move(arg);
    return Init_FMCommand_rlink_thrust(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMCommand msg_;
};

class Init_FMCommand_header
{
public:
  Init_FMCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FMCommand_thrust header(::rotor_tm_msgs::msg::FMCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FMCommand_thrust(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::FMCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_FMCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__BUILDER_HPP_
