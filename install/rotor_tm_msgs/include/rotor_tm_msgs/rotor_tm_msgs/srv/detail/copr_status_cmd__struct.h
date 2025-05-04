// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotor_tm_msgs:srv/CoprStatusCmd.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__COPR_STATUS_CMD__STRUCT_H_
#define ROTOR_TM_MSGS__SRV__DETAIL__COPR_STATUS_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CoprStatusCmd in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__srv__CoprStatusCmd_Request
{
  uint8_t copr_status;
} rotor_tm_msgs__srv__CoprStatusCmd_Request;

// Struct for a sequence of rotor_tm_msgs__srv__CoprStatusCmd_Request.
typedef struct rotor_tm_msgs__srv__CoprStatusCmd_Request__Sequence
{
  rotor_tm_msgs__srv__CoprStatusCmd_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__srv__CoprStatusCmd_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CoprStatusCmd in the package rotor_tm_msgs.
typedef struct rotor_tm_msgs__srv__CoprStatusCmd_Response
{
  bool success;
  rosidl_runtime_c__String message;
} rotor_tm_msgs__srv__CoprStatusCmd_Response;

// Struct for a sequence of rotor_tm_msgs__srv__CoprStatusCmd_Response.
typedef struct rotor_tm_msgs__srv__CoprStatusCmd_Response__Sequence
{
  rotor_tm_msgs__srv__CoprStatusCmd_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotor_tm_msgs__srv__CoprStatusCmd_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__COPR_STATUS_CMD__STRUCT_H_
