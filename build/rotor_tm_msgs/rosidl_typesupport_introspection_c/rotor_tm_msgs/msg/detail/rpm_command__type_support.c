// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:msg/RPMCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/msg/detail/rpm_command__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/msg/detail/rpm_command__functions.h"
#include "rotor_tm_msgs/msg/detail/rpm_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__msg__RPMCommand__init(message_memory);
}

void rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_fini_function(void * message_memory)
{
  rotor_tm_msgs__msg__RPMCommand__fini(message_memory);
}

size_t rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__size_function__RPMCommand__rpms(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__get_const_function__RPMCommand__rpms(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__get_function__RPMCommand__rpms(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__fetch_function__RPMCommand__rpms(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__get_const_function__RPMCommand__rpms(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__assign_function__RPMCommand__rpms(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__get_function__RPMCommand__rpms(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__RPMCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rpms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__RPMCommand, rpms),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__size_function__RPMCommand__rpms,  // size() function pointer
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__get_const_function__RPMCommand__rpms,  // get_const(index) function pointer
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__get_function__RPMCommand__rpms,  // get(index) function pointer
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__fetch_function__RPMCommand__rpms,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__assign_function__RPMCommand__rpms,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_members = {
  "rotor_tm_msgs__msg",  // message namespace
  "RPMCommand",  // message name
  2,  // number of fields
  sizeof(rotor_tm_msgs__msg__RPMCommand),
  rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_member_array,  // message members
  rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_type_support_handle = {
  0,
  &rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, RPMCommand)() {
  rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__msg__RPMCommand__rosidl_typesupport_introspection_c__RPMCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
