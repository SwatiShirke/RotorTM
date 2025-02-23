// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/FMNCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__STRUCT_H_

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
// Member 'rlink_thrust'
// Member 'moments'
// Member 'null_space_vec'
// Member 'acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/FMNCommand in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__msg__FMNCommand
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Vector3 rlink_thrust;
  geometry_msgs__msg__Vector3 moments;
  geometry_msgs__msg__Vector3 null_space_vec;
  geometry_msgs__msg__Vector3 acceleration;
} rotor_tm_msgs__msg__FMNCommand;

// Struct for a sequence of rotor_tm_msgs__msg__FMNCommand.
typedef struct rotor_tm_msgs__msg__FMNCommand__Sequence
{
  rotor_tm_msgs__msg__FMNCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__FMNCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__STRUCT_H_
