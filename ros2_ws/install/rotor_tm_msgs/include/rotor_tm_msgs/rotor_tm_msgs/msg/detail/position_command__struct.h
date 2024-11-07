// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/PositionCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__STRUCT_H_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'velocity'
// Member 'acceleration'
// Member 'jerk'
// Member 'angular_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/PositionCommand in the package rotor_tm_msgs.
/**
  * Include the header
 */
typedef struct rotor_tm_msgs__msg__PositionCommand
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point position;
  geometry_msgs__msg__Vector3 velocity;
  geometry_msgs__msg__Vector3 acceleration;
  geometry_msgs__msg__Vector3 jerk;
  geometry_msgs__msg__Quaternion quaternion;
  geometry_msgs__msg__Vector3 angular_velocity;
  double kx[3];
  double kv[3];
} rotor_tm_msgs__msg__PositionCommand;

// Struct for a sequence of rotor_tm_msgs__msg__PositionCommand.
typedef struct rotor_tm_msgs__msg__PositionCommand__Sequence
{
  rotor_tm_msgs__msg__PositionCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__PositionCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__STRUCT_H_
