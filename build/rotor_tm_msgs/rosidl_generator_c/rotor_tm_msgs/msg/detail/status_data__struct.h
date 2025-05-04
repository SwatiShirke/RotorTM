// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:msg/StatusData.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__STRUCT_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__STRUCT_H_

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
// Member 'status'
#include "std_msgs/msg/detail/string__struct.h"

/// Struct defined in msg/StatusData in the package rotor_tm_msgs.
/**
  * Include the header
 */
typedef struct rotor_tm_msgs__msg__StatusData
{
  std_msgs__msg__Header header;
  std_msgs__msg__String status;
} rotor_tm_msgs__msg__StatusData;

// Struct for a sequence of rotor_tm_msgs__msg__StatusData.
typedef struct rotor_tm_msgs__msg__StatusData__Sequence
{
  rotor_tm_msgs__msg__StatusData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__msg__StatusData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__STRUCT_H_
