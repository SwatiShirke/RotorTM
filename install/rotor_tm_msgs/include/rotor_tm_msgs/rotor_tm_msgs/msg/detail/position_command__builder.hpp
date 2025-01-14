// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/PositionCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/position_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_PositionCommand_kv
{
public:
  explicit Init_PositionCommand_kv(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::PositionCommand kv(::rotor_tm_msgs::msg::PositionCommand::_kv_type arg)
  {
    msg_.kv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_kx
{
public:
  explicit Init_PositionCommand_kx(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_kv kx(::rotor_tm_msgs::msg::PositionCommand::_kx_type arg)
  {
    msg_.kx = std::move(arg);
    return Init_PositionCommand_kv(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_angular_velocity
{
public:
  explicit Init_PositionCommand_angular_velocity(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_kx angular_velocity(::rotor_tm_msgs::msg::PositionCommand::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_PositionCommand_kx(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_quaternion
{
public:
  explicit Init_PositionCommand_quaternion(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_angular_velocity quaternion(::rotor_tm_msgs::msg::PositionCommand::_quaternion_type arg)
  {
    msg_.quaternion = std::move(arg);
    return Init_PositionCommand_angular_velocity(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_jerk
{
public:
  explicit Init_PositionCommand_jerk(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_quaternion jerk(::rotor_tm_msgs::msg::PositionCommand::_jerk_type arg)
  {
    msg_.jerk = std::move(arg);
    return Init_PositionCommand_quaternion(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_acceleration
{
public:
  explicit Init_PositionCommand_acceleration(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_jerk acceleration(::rotor_tm_msgs::msg::PositionCommand::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_PositionCommand_jerk(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_velocity
{
public:
  explicit Init_PositionCommand_velocity(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_acceleration velocity(::rotor_tm_msgs::msg::PositionCommand::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_PositionCommand_acceleration(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_position
{
public:
  explicit Init_PositionCommand_position(::rotor_tm_msgs::msg::PositionCommand & msg)
  : msg_(msg)
  {}
  Init_PositionCommand_velocity position(::rotor_tm_msgs::msg::PositionCommand::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_PositionCommand_velocity(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

class Init_PositionCommand_header
{
public:
  Init_PositionCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PositionCommand_position header(::rotor_tm_msgs::msg::PositionCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PositionCommand_position(msg_);
  }

private:
  ::rotor_tm_msgs::msg::PositionCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::PositionCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_PositionCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__BUILDER_HPP_
