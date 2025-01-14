// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:msg/TrajCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/msg/detail/traj_command__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/msg/detail/traj_command__functions.h"
#include "rotor_tm_msgs/msg/detail/traj_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `points`
#include "rotor_tm_msgs/msg/position_command.h"
// Member `points`
#include "rotor_tm_msgs/msg/detail/position_command__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__msg__TrajCommand__init(message_memory);
}

void rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_fini_function(void * message_memory)
{
  rotor_tm_msgs__msg__TrajCommand__fini(message_memory);
}

size_t rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__size_function__TrajCommand__points(
  const void * untyped_member)
{
  const rotor_tm_msgs__msg__PositionCommand__Sequence * member =
    (const rotor_tm_msgs__msg__PositionCommand__Sequence *)(untyped_member);
  return member->size;
}

const void * rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__get_const_function__TrajCommand__points(
  const void * untyped_member, size_t index)
{
  const rotor_tm_msgs__msg__PositionCommand__Sequence * member =
    (const rotor_tm_msgs__msg__PositionCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__get_function__TrajCommand__points(
  void * untyped_member, size_t index)
{
  rotor_tm_msgs__msg__PositionCommand__Sequence * member =
    (rotor_tm_msgs__msg__PositionCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__fetch_function__TrajCommand__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rotor_tm_msgs__msg__PositionCommand * item =
    ((const rotor_tm_msgs__msg__PositionCommand *)
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__get_const_function__TrajCommand__points(untyped_member, index));
  rotor_tm_msgs__msg__PositionCommand * value =
    (rotor_tm_msgs__msg__PositionCommand *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__assign_function__TrajCommand__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rotor_tm_msgs__msg__PositionCommand * item =
    ((rotor_tm_msgs__msg__PositionCommand *)
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__get_function__TrajCommand__points(untyped_member, index));
  const rotor_tm_msgs__msg__PositionCommand * value =
    (const rotor_tm_msgs__msg__PositionCommand *)(untyped_value);
  *item = *value;
}

bool rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__resize_function__TrajCommand__points(
  void * untyped_member, size_t size)
{
  rotor_tm_msgs__msg__PositionCommand__Sequence * member =
    (rotor_tm_msgs__msg__PositionCommand__Sequence *)(untyped_member);
  rotor_tm_msgs__msg__PositionCommand__Sequence__fini(member);
  return rotor_tm_msgs__msg__PositionCommand__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TrajCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__TrajCommand, points),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__size_function__TrajCommand__points,  // size() function pointer
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__get_const_function__TrajCommand__points,  // get_const(index) function pointer
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__get_function__TrajCommand__points,  // get(index) function pointer
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__fetch_function__TrajCommand__points,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__assign_function__TrajCommand__points,  // assign(index, value) function pointer
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__resize_function__TrajCommand__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_members = {
  "rotor_tm_msgs__msg",  // message namespace
  "TrajCommand",  // message name
  2,  // number of fields
  sizeof(rotor_tm_msgs__msg__TrajCommand),
  rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_member_array,  // message members
  rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_type_support_handle = {
  0,
  &rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, TrajCommand)() {
  rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, PositionCommand)();
  if (!rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__msg__TrajCommand__rosidl_typesupport_introspection_c__TrajCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
