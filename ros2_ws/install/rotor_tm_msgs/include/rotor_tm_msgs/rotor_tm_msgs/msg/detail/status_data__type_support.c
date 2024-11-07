// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:msg/StatusData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/msg/detail/status_data__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/msg/detail/status_data__functions.h"
#include "rotor_tm_msgs/msg/detail/status_data__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `status`
#include "std_msgs/msg/string.h"
// Member `status`
#include "std_msgs/msg/detail/string__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__msg__StatusData__init(message_memory);
}

void rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_fini_function(void * message_memory)
{
  rotor_tm_msgs__msg__StatusData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__StatusData, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__msg__StatusData, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_members = {
  "rotor_tm_msgs__msg",  // message namespace
  "StatusData",  // message name
  2,  // number of fields
  sizeof(rotor_tm_msgs__msg__StatusData),
  rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_member_array,  // message members
  rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_type_support_handle = {
  0,
  &rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, StatusData)() {
  rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, String)();
  if (!rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__msg__StatusData__rosidl_typesupport_introspection_c__StatusData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
