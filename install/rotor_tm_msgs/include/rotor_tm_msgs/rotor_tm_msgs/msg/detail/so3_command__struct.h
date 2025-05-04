// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/SO3Command.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__STRUCT_H_

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
// Member 'force'
// Member 'angular_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/SO3Command in the package rotor_tm_msgs.
/**
  * Include the header
 */
typedef struct rotor_tm_msgs__msg__SO3Command
{
  std_msgs__msg__Header header;
  /// Vector3 from geometry_msgs
  geometry_msgs__msg__Vector3 force;
  geometry_msgs__msg__Quaternion orientation;
  geometry_msgs__msg__Vector3 angular_velocity;
  /// Use float64[] for arrays in ROS2
  double k_r[3];
  double k_om[3];
} rotor_tm_msgs__msg__SO3Command;

// Struct for a sequence of rotor_tm_msgs__msg__SO3Command.
typedef struct rotor_tm_msgs__msg__SO3Command__Sequence
{
  rotor_tm_msgs__msg__SO3Command * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__SO3Command__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__STRUCT_H_
