// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rotor_tm_msgs:msg/CenPLCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__TRAITS_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rotor_tm_msgs/msg/detail/cen_pl_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pos_cmd'
#include "rotor_tm_msgs/msg/detail/position_command__traits.hpp"
// Member 'acc'
// Member 'estimated_acc'
// Member 'mu'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace rotor_tm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CenPLCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pos_cmd
  {
    out << "pos_cmd: ";
    to_flow_style_yaml(msg.pos_cmd, out);
    out << ", ";
  }

  // member: acc
  {
    if (msg.acc.size() == 0) {
      out << "acc: []";
    } else {
      out << "acc: [";
      size_t pending_items = msg.acc.size();
      for (auto item : msg.acc) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: estimated_acc
  {
    if (msg.estimated_acc.size() == 0) {
      out << "estimated_acc: []";
    } else {
      out << "estimated_acc: [";
      size_t pending_items = msg.estimated_acc.size();
      for (auto item : msg.estimated_acc) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: mu
  {
    if (msg.mu.size() == 0) {
      out << "mu: []";
    } else {
      out << "mu: [";
      size_t pending_items = msg.mu.size();
      for (auto item : msg.mu) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: copr_status
  {
    out << "copr_status: ";
    rosidl_generator_traits::value_to_yaml(msg.copr_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CenPLCommand & msg,
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

  // member: pos_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_cmd:\n";
    to_block_style_yaml(msg.pos_cmd, out, indentation + 2);
  }

  // member: acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.acc.size() == 0) {
      out << "acc: []\n";
    } else {
      out << "acc:\n";
      for (auto item : msg.acc) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: estimated_acc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.estimated_acc.size() == 0) {
      out << "estimated_acc: []\n";
    } else {
      out << "estimated_acc:\n";
      for (auto item : msg.estimated_acc) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: mu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.mu.size() == 0) {
      out << "mu: []\n";
    } else {
      out << "mu:\n";
      for (auto item : msg.mu) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: copr_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "copr_status: ";
    rosidl_generator_traits::value_to_yaml(msg.copr_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CenPLCommand & msg, bool use_flow_style = false)
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
  const rotor_tm_msgs::msg::CenPLCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::msg::CenPLCommand & msg)
{
  return rotor_tm_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::msg::CenPLCommand>()
{
  return "rotor_tm_msgs::msg::CenPLCommand";
}

template<>
inline const char * name<rotor_tm_msgs::msg::CenPLCommand>()
{
  return "rotor_tm_msgs/msg/CenPLCommand";
}

template<>
struct has_fixed_size<rotor_tm_msgs::msg::CenPLCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rotor_tm_msgs::msg::CenPLCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rotor_tm_msgs::msg::CenPLCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__TRAITS_HPP_
