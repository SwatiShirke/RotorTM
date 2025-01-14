// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rotor_tm_msgs:msg/RPMCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__TRAITS_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rotor_tm_msgs/msg/detail/rpm_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rotor_tm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RPMCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: rpms
  {
    if (msg.rpms.size() == 0) {
      out << "rpms: []";
    } else {
      out << "rpms: [";
      size_t pending_items = msg.rpms.size();
      for (auto item : msg.rpms) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RPMCommand & msg,
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

  // member: rpms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rpms.size() == 0) {
      out << "rpms: []\n";
    } else {
      out << "rpms:\n";
      for (auto item : msg.rpms) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RPMCommand & msg, bool use_flow_style = false)
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
  const rotor_tm_msgs::msg::RPMCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::msg::RPMCommand & msg)
{
  return rotor_tm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::msg::RPMCommand>()
{
  return "rotor_tm_msgs::msg::RPMCommand";
}

template<>
inline const char * name<rotor_tm_msgs::msg::RPMCommand>()
{
  return "rotor_tm_msgs/msg/RPMCommand";
}

template<>
struct has_fixed_size<rotor_tm_msgs::msg::RPMCommand>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<rotor_tm_msgs::msg::RPMCommand>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<rotor_tm_msgs::msg::RPMCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__TRAITS_HPP_
