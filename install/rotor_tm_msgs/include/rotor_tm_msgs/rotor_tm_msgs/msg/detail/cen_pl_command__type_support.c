// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:msg/CenPLCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/msg/detail/cen_pl_command__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/msg/detail/cen_pl_command__functions.h"
#include "rotor_tm_msgs/msg/detail/cen_pl_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `pos_cmd`
#include "rotor_tm_msgs/msg/position_command.h"
// Member `pos_cmd`
#include "rotor_tm_msgs/msg/detail/position_command__rosidl_typesupport_introspection_c.h"
// Member `acc`
// Member `estimated_acc`
// Member `mu`
#include "geometry_msgs/msg/vector3.h"
// Member `acc`
// Member `estimated_acc`
// Member `mu`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__msg__CenPLCommand__init(message_memory);
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_fini_function(void * message_memory)
{
  rotor_tm_msgs__msg__CenPLCommand__fini(message_memory);
}

size_t rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__size_function__CenPLCommand__acc(
  const void * untyped_member)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return member->size;
}

const void * rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__acc(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__acc(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__fetch_function__CenPLCommand__acc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Vector3 * item =
    ((const geometry_msgs__msg__Vector3 *)
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__acc(untyped_member, index));
  geometry_msgs__msg__Vector3 * value =
    (geometry_msgs__msg__Vector3 *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__assign_function__CenPLCommand__acc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Vector3 * item =
    ((geometry_msgs__msg__Vector3 *)
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__acc(untyped_member, index));
  const geometry_msgs__msg__Vector3 * value =
    (const geometry_msgs__msg__Vector3 *)(untyped_value);
  *item = *value;
}

bool rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__resize_function__CenPLCommand__acc(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  geometry_msgs__msg__Vector3__Sequence__fini(member);
  return geometry_msgs__msg__Vector3__Sequence__init(member, size);
}

size_t rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__size_function__CenPLCommand__estimated_acc(
  const void * untyped_member)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return member->size;
}

const void * rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__estimated_acc(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__estimated_acc(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__fetch_function__CenPLCommand__estimated_acc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Vector3 * item =
    ((const geometry_msgs__msg__Vector3 *)
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__estimated_acc(untyped_member, index));
  geometry_msgs__msg__Vector3 * value =
    (geometry_msgs__msg__Vector3 *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__assign_function__CenPLCommand__estimated_acc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Vector3 * item =
    ((geometry_msgs__msg__Vector3 *)
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__estimated_acc(untyped_member, index));
  const geometry_msgs__msg__Vector3 * value =
    (const geometry_msgs__msg__Vector3 *)(untyped_value);
  *item = *value;
}

bool rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__resize_function__CenPLCommand__estimated_acc(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  geometry_msgs__msg__Vector3__Sequence__fini(member);
  return geometry_msgs__msg__Vector3__Sequence__init(member, size);
}

size_t rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__size_function__CenPLCommand__mu(
  const void * untyped_member)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return member->size;
}

const void * rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__mu(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__mu(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__fetch_function__CenPLCommand__mu(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Vector3 * item =
    ((const geometry_msgs__msg__Vector3 *)
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__mu(untyped_member, index));
  geometry_msgs__msg__Vector3 * value =
    (geometry_msgs__msg__Vector3 *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__assign_function__CenPLCommand__mu(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Vector3 * item =
    ((geometry_msgs__msg__Vector3 *)
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__mu(untyped_member, index));
  const geometry_msgs__msg__Vector3 * value =
    (const geometry_msgs__msg__Vector3 *)(untyped_value);
  *item = *value;
}

bool rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__resize_function__CenPLCommand__mu(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  geometry_msgs__msg__Vector3__Sequence__fini(member);
  return geometry_msgs__msg__Vector3__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__CenPLCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__CenPLCommand, pos_cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__CenPLCommand, acc),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__size_function__CenPLCommand__acc,  // size() function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__acc,  // get_const(index) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__acc,  // get(index) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__fetch_function__CenPLCommand__acc,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__assign_function__CenPLCommand__acc,  // assign(index, value) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__resize_function__CenPLCommand__acc  // resize(index) function pointer
  },
  {
    "estimated_acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__CenPLCommand, estimated_acc),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__size_function__CenPLCommand__estimated_acc,  // size() function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__estimated_acc,  // get_const(index) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__estimated_acc,  // get(index) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__fetch_function__CenPLCommand__estimated_acc,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__assign_function__CenPLCommand__estimated_acc,  // assign(index, value) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__resize_function__CenPLCommand__estimated_acc  // resize(index) function pointer
  },
  {
    "mu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__CenPLCommand, mu),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__size_function__CenPLCommand__mu,  // size() function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_const_function__CenPLCommand__mu,  // get_const(index) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__get_function__CenPLCommand__mu,  // get(index) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__fetch_function__CenPLCommand__mu,  // fetch(index, &value) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__assign_function__CenPLCommand__mu,  // assign(index, value) function pointer
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__resize_function__CenPLCommand__mu  // resize(index) function pointer
  },
  {
    "copr_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__CenPLCommand, copr_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_members = {
  "rotor_tm_msgs__msg",  // message namespace
  "CenPLCommand",  // message name
  6,  // number of fields
  sizeof(rotor_tm_msgs__msg__CenPLCommand),
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array,  // message members
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_type_support_handle = {
  0,
  &rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, CenPLCommand)() {
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, PositionCommand)();
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__msg__CenPLCommand__rosidl_typesupport_introspection_c__CenPLCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
