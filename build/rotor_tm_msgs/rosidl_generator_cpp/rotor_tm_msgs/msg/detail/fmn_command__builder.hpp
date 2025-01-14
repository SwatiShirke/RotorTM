// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/FMNCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/fmn_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_FMNCommand_null_space_vec
{
public:
  explicit Init_FMNCommand_null_space_vec(::rotor_tm_msgs::msg::FMNCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::FMNCommand null_space_vec(::rotor_tm_msgs::msg::FMNCommand::_null_space_vec_type arg)
  {
    msg_.null_space_vec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMNCommand msg_;
};

class Init_FMNCommand_moments
{
public:
  explicit Init_FMNCommand_moments(::rotor_tm_msgs::msg::FMNCommand & msg)
  : msg_(msg)
  {}
  Init_FMNCommand_null_space_vec moments(::rotor_tm_msgs::msg::FMNCommand::_moments_type arg)
  {
    msg_.moments = std::move(arg);
    return Init_FMNCommand_null_space_vec(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMNCommand msg_;
};

class Init_FMNCommand_rlink_thrust
{
public:
  explicit Init_FMNCommand_rlink_thrust(::rotor_tm_msgs::msg::FMNCommand & msg)
  : msg_(msg)
  {}
  Init_FMNCommand_moments rlink_thrust(::rotor_tm_msgs::msg::FMNCommand::_rlink_thrust_type arg)
  {
    msg_.rlink_thrust = std::move(arg);
    return Init_FMNCommand_moments(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMNCommand msg_;
};

class Init_FMNCommand_header
{
public:
  Init_FMNCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FMNCommand_rlink_thrust header(::rotor_tm_msgs::msg::FMNCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FMNCommand_rlink_thrust(msg_);
  }

private:
  ::rotor_tm_msgs::msg::FMNCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::FMNCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_FMNCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__BUILDER_HPP_
