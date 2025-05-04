// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rotor_tm_msgs:msg/PositionCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__TRAITS_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rotor_tm_msgs/msg/detail/position_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'velocity'
// Member 'acceleration'
// Member 'jerk'
// Member 'angular_velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace rotor_tm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PositionCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    to_flow_style_yaml(msg.acceleration, out);
    out << ", ";
  }

  // member: jerk
  {
    out << "jerk: ";
    to_flow_style_yaml(msg.jerk, out);
    out << ", ";
  }

  // member: quaternion
  {
    out << "quaternion: ";
    to_flow_style_yaml(msg.quaternion, out);
    out << ", ";
  }

  // member: angular_velocity
  {
    out << "angular_velocity: ";
    to_flow_style_yaml(msg.angular_velocity, out);
    out << ", ";
  }

  // member: kx
  {
    if (msg.kx.size() == 0) {
      out << "kx: []";
    } else {
      out << "kx: [";
      size_t pending_items = msg.kx.size();
      for (auto item : msg.kx) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: kv
  {
    if (msg.kv.size() == 0) {
      out << "kv: []";
    } else {
      out << "kv: [";
      size_t pending_items = msg.kv.size();
      for (auto item : msg.kv) {
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
  const PositionCommand & msg,
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

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration:\n";
    to_block_style_yaml(msg.acceleration, out, indentation + 2);
  }

  // member: jerk
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "jerk:\n";
    to_block_style_yaml(msg.jerk, out, indentation + 2);
  }

  // member: quaternion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quaternion:\n";
    to_block_style_yaml(msg.quaternion, out, indentation + 2);
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity:\n";
    to_block_style_yaml(msg.angular_velocity, out, indentation + 2);
  }

  // member: kx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kx.size() == 0) {
      out << "kx: []\n";
    } else {
      out << "kx:\n";
      for (auto item : msg.kx) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: kv
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kv.size() == 0) {
      out << "kv: []\n";
    } else {
      out << "kv:\n";
      for (auto item : msg.kv) {
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

inline std::string to_yaml(const PositionCommand & msg, bool use_flow_style = false)
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
  const rotor_tm_msgs::msg::PositionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::msg::PositionCommand & msg)
{
  return rotor_tm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::msg::PositionCommand>()
{
  return "rotor_tm_msgs::msg::PositionCommand";
}

template<>
inline const char * name<rotor_tm_msgs::msg::PositionCommand>()
{
  return "rotor_tm_msgs/msg/PositionCommand";
}

template<>
struct has_fixed_size<rotor_tm_msgs::msg::PositionCommand>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Quaternion>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<rotor_tm_msgs::msg::PositionCommand>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Quaternion>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<rotor_tm_msgs::msg::PositionCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__TRAITS_HPP_
