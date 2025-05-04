// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rotor_tm_msgs:srv/CircleWithRotation.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__CIRCLE_WITH_ROTATION__TRAITS_HPP_
#define ROTOR_TM_MSGS__SRV__DETAIL__CIRCLE_WITH_ROTATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rotor_tm_msgs/srv/detail/circle_with_rotation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rotor_tm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CircleWithRotation_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << ", ";
  }

  // member: angle_amp
  {
    if (msg.angle_amp.size() == 0) {
      out << "angle_amp: []";
    } else {
      out << "angle_amp: [";
      size_t pending_items = msg.angle_amp.size();
      for (auto item : msg.angle_amp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tp
  {
    out << "tp: ";
    rosidl_generator_traits::value_to_yaml(msg.tp, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CircleWithRotation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }

  // member: angle_amp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angle_amp.size() == 0) {
      out << "angle_amp: []\n";
    } else {
      out << "angle_amp:\n";
      for (auto item : msg.angle_amp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tp: ";
    rosidl_generator_traits::value_to_yaml(msg.tp, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CircleWithRotation_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rotor_tm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rotor_tm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rotor_tm_msgs::srv::CircleWithRotation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::srv::CircleWithRotation_Request & msg)
{
  return rotor_tm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::srv::CircleWithRotation_Request>()
{
  return "rotor_tm_msgs::srv::CircleWithRotation_Request";
}

template<>
inline const char * name<rotor_tm_msgs::srv::CircleWithRotation_Request>()
{
  return "rotor_tm_msgs/srv/CircleWithRotation_Request";
}

template<>
struct has_fixed_size<rotor_tm_msgs::srv::CircleWithRotation_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rotor_tm_msgs::srv::CircleWithRotation_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rotor_tm_msgs::srv::CircleWithRotation_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rotor_tm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const CircleWithRotation_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CircleWithRotation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CircleWithRotation_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rotor_tm_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rotor_tm_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rotor_tm_msgs::srv::CircleWithRotation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rotor_tm_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rotor_tm_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rotor_tm_msgs::srv::CircleWithRotation_Response & msg)
{
  return rotor_tm_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rotor_tm_msgs::srv::CircleWithRotation_Response>()
{
  return "rotor_tm_msgs::srv::CircleWithRotation_Response";
}

template<>
inline const char * name<rotor_tm_msgs::srv::CircleWithRotation_Response>()
{
  return "rotor_tm_msgs/srv/CircleWithRotation_Response";
}

template<>
struct has_fixed_size<rotor_tm_msgs::srv::CircleWithRotation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rotor_tm_msgs::srv::CircleWithRotation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rotor_tm_msgs::srv::CircleWithRotation_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rotor_tm_msgs::srv::CircleWithRotation>()
{
  return "rotor_tm_msgs::srv::CircleWithRotation";
}

template<>
inline const char * name<rotor_tm_msgs::srv::CircleWithRotation>()
{
  return "rotor_tm_msgs/srv/CircleWithRotation";
}

template<>
struct has_fixed_size<rotor_tm_msgs::srv::CircleWithRotation>
  : std::integral_constant<
    bool,
    has_fixed_size<rotor_tm_msgs::srv::CircleWithRotation_Request>::value &&
    has_fixed_size<rotor_tm_msgs::srv::CircleWithRotation_Response>::value
  >
{
};

template<>
struct has_bounded_size<rotor_tm_msgs::srv::CircleWithRotation>
  : std::integral_constant<
    bool,
    has_bounded_size<rotor_tm_msgs::srv::CircleWithRotation_Request>::value &&
    has_bounded_size<rotor_tm_msgs::srv::CircleWithRotation_Response>::value
  >
{
};

template<>
struct is_service<rotor_tm_msgs::srv::CircleWithRotation>
  : std::true_type
{
};

template<>
struct is_service_request<rotor_tm_msgs::srv::CircleWithRotation_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rotor_tm_msgs::srv::CircleWithRotation_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__CIRCLE_WITH_ROTATION__TRAITS_HPP_
