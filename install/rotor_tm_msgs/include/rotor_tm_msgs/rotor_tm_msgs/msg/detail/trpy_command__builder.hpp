// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/TRPYCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__TRPY_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__TRPY_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/trpy_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_TRPYCommand_k_om
{
public:
  explicit Init_TRPYCommand_k_om(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::TRPYCommand k_om(::rotor_tm_msgs::msg::TRPYCommand::_k_om_type arg)
  {
    msg_.k_om = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_k_r
{
public:
  explicit Init_TRPYCommand_k_r(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_k_om k_r(::rotor_tm_msgs::msg::TRPYCommand::_k_r_type arg)
  {
    msg_.k_r = std::move(arg);
    return Init_TRPYCommand_k_om(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_quaternion
{
public:
  explicit Init_TRPYCommand_quaternion(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_k_r quaternion(::rotor_tm_msgs::msg::TRPYCommand::_quaternion_type arg)
  {
    msg_.quaternion = std::move(arg);
    return Init_TRPYCommand_k_r(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_angular_velocity
{
public:
  explicit Init_TRPYCommand_angular_velocity(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_quaternion angular_velocity(::rotor_tm_msgs::msg::TRPYCommand::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_TRPYCommand_quaternion(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_yaw
{
public:
  explicit Init_TRPYCommand_yaw(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_angular_velocity yaw(::rotor_tm_msgs::msg::TRPYCommand::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_TRPYCommand_angular_velocity(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_pitch
{
public:
  explicit Init_TRPYCommand_pitch(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_yaw pitch(::rotor_tm_msgs::msg::TRPYCommand::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_TRPYCommand_yaw(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_roll
{
public:
  explicit Init_TRPYCommand_roll(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_pitch roll(::rotor_tm_msgs::msg::TRPYCommand::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_TRPYCommand_pitch(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_thrust
{
public:
  explicit Init_TRPYCommand_thrust(::rotor_tm_msgs::msg::TRPYCommand & msg)
  : msg_(msg)
  {}
  Init_TRPYCommand_roll thrust(::rotor_tm_msgs::msg::TRPYCommand::_thrust_type arg)
  {
    msg_.thrust = std::move(arg);
    return Init_TRPYCommand_roll(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

class Init_TRPYCommand_header
{
public:
  Init_TRPYCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TRPYCommand_thrust header(::rotor_tm_msgs::msg::TRPYCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TRPYCommand_thrust(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TRPYCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::TRPYCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_TRPYCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__TRPY_COMMAND__BUILDER_HPP_
