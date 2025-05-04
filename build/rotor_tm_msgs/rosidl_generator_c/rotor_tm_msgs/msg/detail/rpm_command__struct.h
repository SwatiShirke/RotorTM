// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/RPMCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__STRUCT_H_

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

/// Struct defined in msg/RPMCommand in the package rotor_tm_msgs.
/**
  * Import the Header type from std_msgs
 */
typedef struct rotor_tm_msgs__msg__RPMCommand
{
  std_msgs__msg__Header header;
  /// Use int32[] for the array of RPMs
  /// This will allow for a dynamic size of the array
  int32_t rpms[4];
} rotor_tm_msgs__msg__RPMCommand;

// Struct for a sequence of rotor_tm_msgs__msg__RPMCommand.
typedef struct rotor_tm_msgs__msg__RPMCommand__Sequence
{
  rotor_tm_msgs__msg__RPMCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__RPMCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__RPM_COMMAND__STRUCT_H_
