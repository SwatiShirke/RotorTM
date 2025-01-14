// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/TrajCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__TRAJ_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__TRAJ_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/traj_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_TrajCommand_points
{
public:
  explicit Init_TrajCommand_points(::rotor_tm_msgs::msg::TrajCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::TrajCommand points(::rotor_tm_msgs::msg::TrajCommand::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TrajCommand msg_;
};

class Init_TrajCommand_header
{
public:
  Init_TrajCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajCommand_points header(::rotor_tm_msgs::msg::TrajCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TrajCommand_points(msg_);
  }

private:
  ::rotor_tm_msgs::msg::TrajCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::TrajCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_TrajCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__TRAJ_COMMAND__BUILDER_HPP_
