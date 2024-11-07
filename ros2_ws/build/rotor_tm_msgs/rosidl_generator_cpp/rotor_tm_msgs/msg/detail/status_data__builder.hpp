// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:msg/StatusData.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__BUILDER_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/msg/detail/status_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace msg
{

namespace builder
{

class Init_StatusData_status
{
public:
  explicit Init_StatusData_status(::rotor_tm_msgs::msg::StatusData & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::msg::StatusData status(::rotor_tm_msgs::msg::StatusData::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::msg::StatusData msg_;
};

class Init_StatusData_header
{
public:
  Init_StatusData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StatusData_status header(::rotor_tm_msgs::msg::StatusData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_StatusData_status(msg_);
  }

private:
  ::rotor_tm_msgs::msg::StatusData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::msg::StatusData>()
{
  return rotor_tm_msgs::msg::builder::Init_StatusData_header();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__BUILDER_HPP_
