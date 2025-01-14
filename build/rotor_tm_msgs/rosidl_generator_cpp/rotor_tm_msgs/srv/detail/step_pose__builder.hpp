// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotor_tm_msgs:srv/StepPose.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__STEP_POSE__BUILDER_HPP_
#define ROTOR_TM_MSGS__SRV__DETAIL__STEP_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotor_tm_msgs/srv/detail/step_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_StepPose_Request_yaw
{
public:
  explicit Init_StepPose_Request_yaw(::rotor_tm_msgs::srv::StepPose_Request & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::srv::StepPose_Request yaw(::rotor_tm_msgs::srv::StepPose_Request::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::StepPose_Request msg_;
};

class Init_StepPose_Request_pitch
{
public:
  explicit Init_StepPose_Request_pitch(::rotor_tm_msgs::srv::StepPose_Request & msg)
  : msg_(msg)
  {}
  Init_StepPose_Request_yaw pitch(::rotor_tm_msgs::srv::StepPose_Request::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_StepPose_Request_yaw(msg_);
  }

private:
  ::rotor_tm_msgs::srv::StepPose_Request msg_;
};

class Init_StepPose_Request_roll
{
public:
  explicit Init_StepPose_Request_roll(::rotor_tm_msgs::srv::StepPose_Request & msg)
  : msg_(msg)
  {}
  Init_StepPose_Request_pitch roll(::rotor_tm_msgs::srv::StepPose_Request::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_StepPose_Request_pitch(msg_);
  }

private:
  ::rotor_tm_msgs::srv::StepPose_Request msg_;
};

class Init_StepPose_Request_position
{
public:
  Init_StepPose_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StepPose_Request_roll position(::rotor_tm_msgs::srv::StepPose_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_StepPose_Request_roll(msg_);
  }

private:
  ::rotor_tm_msgs::srv::StepPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::StepPose_Request>()
{
  return rotor_tm_msgs::srv::builder::Init_StepPose_Request_position();
}

}  // namespace rotor_tm_msgs


namespace rotor_tm_msgs
{

namespace srv
{

namespace builder
{

class Init_StepPose_Response_message
{
public:
  explicit Init_StepPose_Response_message(::rotor_tm_msgs::srv::StepPose_Response & msg)
  : msg_(msg)
  {}
  ::rotor_tm_msgs::srv::StepPose_Response message(::rotor_tm_msgs::srv::StepPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotor_tm_msgs::srv::StepPose_Response msg_;
};

class Init_StepPose_Response_success
{
public:
  Init_StepPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StepPose_Response_message success(::rotor_tm_msgs::srv::StepPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_StepPose_Response_message(msg_);
  }

private:
  ::rotor_tm_msgs::srv::StepPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotor_tm_msgs::srv::StepPose_Response>()
{
  return rotor_tm_msgs::srv::builder::Init_StepPose_Response_success();
}

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__STEP_POSE__BUILDER_HPP_
