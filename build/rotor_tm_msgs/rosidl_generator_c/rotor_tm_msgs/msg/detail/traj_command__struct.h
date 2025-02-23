// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/TrajCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__TRAJ_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__TRAJ_COMMAND__STRUCT_H_

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
// Member 'points'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/TrajCommand in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__msg__TrajCommand
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__float__Sequence points;
} rotor_tm_msgs__msg__TrajCommand;

// Struct for a sequence of rotor_tm_msgs__msg__TrajCommand.
typedef struct rotor_tm_msgs__msg__TrajCommand__Sequence
{
  rotor_tm_msgs__msg__TrajCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__TrajCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__TRAJ_COMMAND__STRUCT_H_
