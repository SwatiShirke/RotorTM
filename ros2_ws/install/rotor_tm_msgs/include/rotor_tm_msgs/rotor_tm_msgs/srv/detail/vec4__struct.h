// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:srv/Vec4.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__VEC4__STRUCT_H_
#define ROTOR_TM_MSGS__SRV__DETAIL__VEC4__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Vec4 in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__srv__Vec4_Request
{
  float goal[4];
} rotor_tm_msgs__srv__Vec4_Request;

// Struct for a sequence of rotor_tm_msgs__srv__Vec4_Request.
typedef struct rotor_tm_msgs__srv__Vec4_Request__Sequence
{
  rotor_tm_msgs__srv__Vec4_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__srv__Vec4_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Vec4 in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__srv__Vec4_Response
{
  bool success;
  rosidl_runtime_c__String message;
} rotor_tm_msgs__srv__Vec4_Response;

// Struct for a sequence of rotor_tm_msgs__srv__Vec4_Response.
typedef struct rotor_tm_msgs__srv__Vec4_Response__Sequence
{
  rotor_tm_msgs__srv__Vec4_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__srv__Vec4_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__VEC4__STRUCT_H_
