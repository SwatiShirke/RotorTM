// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:msg/TRPYCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/msg/detail/trpy_command__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/msg/detail/trpy_command__functions.h"
#include "rotor_tm_msgs/msg/detail/trpy_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `angular_velocity`
#include "geometry_msgs/msg/vector3.h"
// Member `angular_velocity`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `quaternion`
#include "geometry_msgs/msg/quaternion.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__msg__TRPYCommand__init(message_memory);
}

void rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_fini_function(void * message_memory)
{
  rotor_tm_msgs__msg__TRPYCommand__fini(message_memory);
}

size_t rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__size_function__TRPYCommand__k_r(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_const_function__TRPYCommand__k_r(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_function__TRPYCommand__k_r(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__fetch_function__TRPYCommand__k_r(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_const_function__TRPYCommand__k_r(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__assign_function__TRPYCommand__k_r(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_function__TRPYCommand__k_r(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__size_function__TRPYCommand__k_om(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_const_function__TRPYCommand__k_om(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_function__TRPYCommand__k_om(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__fetch_function__TRPYCommand__k_om(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_const_function__TRPYCommand__k_om(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__assign_function__TRPYCommand__k_om(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_function__TRPYCommand__k_om(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thrust",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, thrust),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quaternion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, quaternion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "k_r",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, k_r),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__size_function__TRPYCommand__k_r,  // size() function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_const_function__TRPYCommand__k_r,  // get_const(index) function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_function__TRPYCommand__k_r,  // get(index) function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__fetch_function__TRPYCommand__k_r,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__assign_function__TRPYCommand__k_r,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "k_om",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TRPYCommand, k_om),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__size_function__TRPYCommand__k_om,  // size() function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_const_function__TRPYCommand__k_om,  // get_const(index) function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__get_function__TRPYCommand__k_om,  // get(index) function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__fetch_function__TRPYCommand__k_om,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__assign_function__TRPYCommand__k_om,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_members = {
  "rotor_tm_msgs__msg",  // message namespace
  "TRPYCommand",  // message name
  9,  // number of fields
  sizeof(rotor_tm_msgs__msg__TRPYCommand),
  rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_member_array,  // message members
  rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_type_support_handle = {
  0,
  &rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, TRPYCommand)() {
  rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  if (!rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__msg__TRPYCommand__rosidl_typesupport_introspection_c__TRPYCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
