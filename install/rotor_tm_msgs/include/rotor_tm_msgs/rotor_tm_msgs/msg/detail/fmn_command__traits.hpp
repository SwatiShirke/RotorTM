// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rotor_tm_msgs:msg/FMNCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__TRAITS_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rotor_tm_msgs/msg/detail/fmn_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'rlink_thrust'
// Member 'moments'
// Member 'null_space_vec'
// Member 'acceleration'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace rotor_tm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FMNCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: rlink_thrust
  {
    out << "rlink_thrust: ";
    to_flow_style_yaml(msg.rlink_thrust, out);
    out << ", ";
  }

  // member: moments
  {
    out << "moments: ";
    to_flow_style_yaml(msg.moments, out);
    out << ", ";
  }

  // member: null_space_vec
  {
    out << "null_space_vec: ";
    to_flow_style_yaml(msg.null_space_vec, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    to_flow_style_yaml(msg.acceleration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FMNCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: rlink_thrust
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rlink_thrust:\n";
    to_block_style_yaml(msg.rlink_thrust, out, indentation + 2);
  }

  // member: moments
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "moments:\n";
    to_block_style_yaml(msg.moments, out, indentation + 2);
  }

  // member: null_space_vec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "null_space_vec:\n";
    to_block_style_yaml(msg.null_space_vec, out, indentation + 2);
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration:\n";
    to_block_style_yaml(msg.acceleration, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FMNCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rotor_tm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rotor_tm_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rotor_tm_msgs::msg::FMNCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::msg::FMNCommand & msg)
{
  return rotor_tm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::msg::FMNCommand>()
{
  return "rotor_tm_msgs::msg::FMNCommand";
}

template<>
inline const char * name<rotor_tm_msgs::msg::FMNCommand>()
{
  return "rotor_tm_msgs/msg/FMNCommand";
}

template<>
struct has_fixed_size<rotor_tm_msgs::msg::FMNCommand>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<rotor_tm_msgs::msg::FMNCommand>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<rotor_tm_msgs::msg::FMNCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__TRAITS_HPP_
