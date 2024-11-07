// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:srv/Line.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__LINE__STRUCT_H_
#define ROTOR_TM_MSGS__SRV__DETAIL__LINE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/Line in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__srv__Line_Request
{
  geometry_msgs__msg__Point__Sequence path;
} rotor_tm_msgs__srv__Line_Request;

// Struct for a sequence of rotor_tm_msgs__srv__Line_Request.
typedef struct rotor_tm_msgs__srv__Line_Request__Sequence
{
  rotor_tm_msgs__srv__Line_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__srv__Line_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Line in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__srv__Line_Response
{
  bool success;
  rosidl_runtime_c__String message;
} rotor_tm_msgs__srv__Line_Response;

// Struct for a sequence of rotor_tm_msgs__srv__Line_Response.
typedef struct rotor_tm_msgs__srv__Line_Response__Sequence
{
  rotor_tm_msgs__srv__Line_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__srv__Line_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__LINE__STRUCT_H_
