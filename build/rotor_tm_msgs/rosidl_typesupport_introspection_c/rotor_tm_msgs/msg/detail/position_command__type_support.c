// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:msg/PositionCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/msg/detail/position_command__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/msg/detail/position_command__functions.h"
#include "rotor_tm_msgs/msg/detail/position_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `velocity`
// Member `acceleration`
// Member `jerk`
// Member `angular_velocity`
#include "geometry_msgs/msg/vector3.h"
// Member `velocity`
// Member `acceleration`
// Member `jerk`
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

void rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__msg__PositionCommand__init(message_memory);
}

void rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_fini_function(void * message_memory)
{
  rotor_tm_msgs__msg__PositionCommand__fini(message_memory);
}

size_t rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__size_function__PositionCommand__kx(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_const_function__PositionCommand__kx(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_function__PositionCommand__kx(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__fetch_function__PositionCommand__kx(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_const_function__PositionCommand__kx(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__assign_function__PositionCommand__kx(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_function__PositionCommand__kx(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__size_function__PositionCommand__kv(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_const_function__PositionCommand__kv(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_function__PositionCommand__kv(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__fetch_function__PositionCommand__kv(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_const_function__PositionCommand__kv(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__assign_function__PositionCommand__kv(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_function__PositionCommand__kv(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[9] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, acceleration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "jerk",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, jerk),  // bytes offset in struct
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
    offsetof(rotor_tm_msgs__msg__PositionCommand, quaternion),  // bytes offset in struct
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
    offsetof(rotor_tm_msgs__msg__PositionCommand, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, kx),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__size_function__PositionCommand__kx,  // size() function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_const_function__PositionCommand__kx,  // get_const(index) function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_function__PositionCommand__kx,  // get(index) function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__fetch_function__PositionCommand__kx,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__assign_function__PositionCommand__kx,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kv",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__PositionCommand, kv),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__size_function__PositionCommand__kv,  // size() function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_const_function__PositionCommand__kv,  // get_const(index) function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__get_function__PositionCommand__kv,  // get(index) function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__fetch_function__PositionCommand__kv,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__assign_function__PositionCommand__kv,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_members = {
  "rotor_tm_msgs__msg",  // message namespace
  "PositionCommand",  // message name
  9,  // number of fields
  sizeof(rotor_tm_msgs__msg__PositionCommand),
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array,  // message members
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_type_support_handle = {
  0,
  &rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, PositionCommand)() {
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__msg__PositionCommand__rosidl_typesupport_introspection_c__PositionCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
