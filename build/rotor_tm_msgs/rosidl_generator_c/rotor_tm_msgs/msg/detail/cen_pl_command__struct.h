// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/CenPLCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pos_cmd'
#include "rotor_tm_msgs/msg/detail/position_command__struct.h"
// Member 'acc'
// Member 'estimated_acc'
// Member 'mu'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/CenPLCommand in the package rotor_tm_msgs.
/**
  * constatnts are moved out from here; not allowed in ROS2
  *  Include the header
 */
typedef struct rotor_tm_msgs__msg__CenPLCommand
{
  std_msgs__msg__Header header;
  /// Position command from your custom message type
  rotor_tm_msgs__msg__PositionCommand pos_cmd;
  /// Vector3 arrays from geometry_msgs
  geometry_msgs__msg__Vector3__Sequence acc;
  geometry_msgs__msg__Vector3__Sequence estimated_acc;
  geometry_msgs__msg__Vector3__Sequence mu;
  /// Use a valid field name for uint8
  uint8_t copr_status;
} rotor_tm_msgs__msg__CenPLCommand;

// Struct for a sequence of rotor_tm_msgs__msg__CenPLCommand.
typedef struct rotor_tm_msgs__msg__CenPLCommand__Sequence
{
  rotor_tm_msgs__msg__CenPLCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__CenPLCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__STRUCT_H_
