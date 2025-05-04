// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/SO3Command.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/so3_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_SO3Command_k_om
{
public:
  explicit Init_SO3Command_k_om(::rotor_tm_msgs::msg::SO3Command & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::SO3Command k_om(::rotor_tm_msgs::msg::SO3Command::_k_om_type arg)
  {
    msg_.k_om = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::SO3Command msg_;
};

class Init_SO3Command_k_r
{
public:
  explicit Init_SO3Command_k_r(::rotor_tm_msgs::msg::SO3Command & msg)
  : msg_(msg)
  {}
  Init_SO3Command_k_om k_r(::rotor_tm_msgs::msg::SO3Command::_k_r_type arg)
  {
    msg_.k_r = std::move(arg);
    return Init_SO3Command_k_om(msg_);
  }

private:
  ::rotor_tm_msgs::msg::SO3Command msg_;
};

class Init_SO3Command_angular_velocity
{
public:
  explicit Init_SO3Command_angular_velocity(::rotor_tm_msgs::msg::SO3Command & msg)
  : msg_(msg)
  {}
  Init_SO3Command_k_r angular_velocity(::rotor_tm_msgs::msg::SO3Command::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_SO3Command_k_r(msg_);
  }

private:
  ::rotor_tm_msgs::msg::SO3Command msg_;
};

class Init_SO3Command_orientation
{
public:
  explicit Init_SO3Command_orientation(::rotor_tm_msgs::msg::SO3Command & msg)
  : msg_(msg)
  {}
  Init_SO3Command_angular_velocity orientation(::rotor_tm_msgs::msg::SO3Command::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_SO3Command_angular_velocity(msg_);
  }

private:
  ::rotor_tm_msgs::msg::SO3Command msg_;
};

class Init_SO3Command_force
{
public:
  explicit Init_SO3Command_force(::rotor_tm_msgs::msg::SO3Command & msg)
  : msg_(msg)
  {}
  Init_SO3Command_orientation force(::rotor_tm_msgs::msg::SO3Command::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_SO3Command_orientation(msg_);
  }

private:
  ::rotor_tm_msgs::msg::SO3Command msg_;
};

class Init_SO3Command_header
{
public:
  Init_SO3Command_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SO3Command_force header(::rotor_tm_msgs::msg::SO3Command::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SO3Command_force(msg_);
  }

private:
  ::rotor_tm_msgs::msg::SO3Command msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::SO3Command>()
{
  return rotor_tm_msgs::msg::builder::Init_SO3Command_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__BUILDER_HPP_
