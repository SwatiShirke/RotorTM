// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rotor_tm_msgs:msg/SO3Command.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__TRAITS_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rotor_tm_msgs/msg/detail/so3_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'force'
// Member 'angular_velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace rotor_tm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SO3Command & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: force
  {
    out << "force: ";
    to_flow_style_yaml(msg.force, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    to_flow_style_yaml(msg.orientation, out);
    out << ", ";
  }

  // member: angular_velocity
  {
    out << "angular_velocity: ";
    to_flow_style_yaml(msg.angular_velocity, out);
    out << ", ";
  }

  // member: k_r
  {
    if (msg.k_r.size() == 0) {
      out << "k_r: []";
    } else {
      out << "k_r: [";
      size_t pending_items = msg.k_r.size();
      for (auto item : msg.k_r) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: k_om
  {
    if (msg.k_om.size() == 0) {
      out << "k_om: []";
    } else {
      out << "k_om: [";
      size_t pending_items = msg.k_om.size();
      for (auto item : msg.k_om) {
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
  const SO3Command & msg,
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

  // member: force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force:\n";
    to_block_style_yaml(msg.force, out, indentation + 2);
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation:\n";
    to_block_style_yaml(msg.orientation, out, indentation + 2);
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity:\n";
    to_block_style_yaml(msg.angular_velocity, out, indentation + 2);
  }

  // member: k_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.k_r.size() == 0) {
      out << "k_r: []\n";
    } else {
      out << "k_r:\n";
      for (auto item : msg.k_r) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: k_om
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.k_om.size() == 0) {
      out << "k_om: []\n";
    } else {
      out << "k_om:\n";
      for (auto item : msg.k_om) {
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

inline std::string to_yaml(const SO3Command & msg, bool use_flow_style = false)
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
  const rotor_tm_msgs::msg::SO3Command & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::msg::SO3Command & msg)
{
  return rotor_tm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::msg::SO3Command>()
{
  return "rotor_tm_msgs::msg::SO3Command";
}

template<>
inline const char * name<rotor_tm_msgs::msg::SO3Command>()
{
  return "rotor_tm_msgs/msg/SO3Command";
}

template<>
struct has_fixed_size<rotor_tm_msgs::msg::SO3Command>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Quaternion>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<rotor_tm_msgs::msg::SO3Command>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Quaternion>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<rotor_tm_msgs::msg::SO3Command>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__TRAITS_HPP_