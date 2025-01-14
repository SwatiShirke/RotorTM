// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/RPMCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/rpm_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_RPMCommand_rpms
{
public:
  explicit Init_RPMCommand_rpms(::rotor_tm_msgs::msg::RPMCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::RPMCommand rpms(::rotor_tm_msgs::msg::RPMCommand::_rpms_type arg)
  {
    msg_.rpms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::RPMCommand msg_;
};

class Init_RPMCommand_header
{
public:
  Init_RPMCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RPMCommand_rpms header(::rotor_tm_msgs::msg::RPMCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RPMCommand_rpms(msg_);
  }

private:
  ::rotor_tm_msgs::msg::RPMCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::RPMCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_RPMCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__BUILDER_HPP_
