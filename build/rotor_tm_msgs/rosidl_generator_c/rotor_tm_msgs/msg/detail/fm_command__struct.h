// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/FMCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__STRUCT_H_

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
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/FMCommand in the package rotor_tm_msgs.
/**
  * Import the necessary message types
 */
typedef struct rotor_tm_msgs__msg__FMCommand
{
  std_msgs__msg__Header header;
  double thrust;
  geometry_msgs__msg__Vector3 rlink_thrust;
  geometry_msgs__msg__Vector3 moments;
} rotor_tm_msgs__msg__FMCommand;

// Struct for a sequence of rotor_tm_msgs__msg__FMCommand.
typedef struct rotor_tm_msgs__msg__FMCommand__Sequence
{
  rotor_tm_msgs__msg__FMCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__FMCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__STRUCT_H_
