// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/CenPLCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/cen_pl_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_CenPLCommand_copr_status
{
public:
  explicit Init_CenPLCommand_copr_status(::rotor_tm_msgs::msg::CenPLCommand & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::CenPLCommand copr_status(::rotor_tm_msgs::msg::CenPLCommand::_copr_status_type arg)
  {
    msg_.copr_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::CenPLCommand msg_;
};

class Init_CenPLCommand_mu
{
public:
  explicit Init_CenPLCommand_mu(::rotor_tm_msgs::msg::CenPLCommand & msg)
  : msg_(msg)
  {}
  Init_CenPLCommand_copr_status mu(::rotor_tm_msgs::msg::CenPLCommand::_mu_type arg)
  {
    msg_.mu = std::move(arg);
    return Init_CenPLCommand_copr_status(msg_);
  }

private:
  ::rotor_tm_msgs::msg::CenPLCommand msg_;
};

class Init_CenPLCommand_estimated_acc
{
public:
  explicit Init_CenPLCommand_estimated_acc(::rotor_tm_msgs::msg::CenPLCommand & msg)
  : msg_(msg)
  {}
  Init_CenPLCommand_mu estimated_acc(::rotor_tm_msgs::msg::CenPLCommand::_estimated_acc_type arg)
  {
    msg_.estimated_acc = std::move(arg);
    return Init_CenPLCommand_mu(msg_);
  }

private:
  ::rotor_tm_msgs::msg::CenPLCommand msg_;
};

class Init_CenPLCommand_acc
{
public:
  explicit Init_CenPLCommand_acc(::rotor_tm_msgs::msg::CenPLCommand & msg)
  : msg_(msg)
  {}
  Init_CenPLCommand_estimated_acc acc(::rotor_tm_msgs::msg::CenPLCommand::_acc_type arg)
  {
    msg_.acc = std::move(arg);
    return Init_CenPLCommand_estimated_acc(msg_);
  }

private:
  ::rotor_tm_msgs::msg::CenPLCommand msg_;
};

class Init_CenPLCommand_pos_cmd
{
public:
  explicit Init_CenPLCommand_pos_cmd(::rotor_tm_msgs::msg::CenPLCommand & msg)
  : msg_(msg)
  {}
  Init_CenPLCommand_acc pos_cmd(::rotor_tm_msgs::msg::CenPLCommand::_pos_cmd_type arg)
  {
    msg_.pos_cmd = std::move(arg);
    return Init_CenPLCommand_acc(msg_);
  }

private:
  ::rotor_tm_msgs::msg::CenPLCommand msg_;
};

class Init_CenPLCommand_header
{
public:
  Init_CenPLCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CenPLCommand_pos_cmd header(::rotor_tm_msgs::msg::CenPLCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CenPLCommand_pos_cmd(msg_);
  }

private:
  ::rotor_tm_msgs::msg::CenPLCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::CenPLCommand>()
{
  return rotor_tm_msgs::msg::builder::Init_CenPLCommand_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__BUILDER_HPP_
