// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rotor_tm_msgs:srv/Vec4.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rotor_tm_msgs/srv/detail/vec4__rosidl_typesupport_introspection_c.h"
#include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rotor_tm_msgs/srv/detail/vec4__functions.h"
#include "rotor_tm_msgs/srv/detail/vec4__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__srv__Vec4_Request__init(message_memory);
}

void rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_fini_function(void * message_memory)
{
  rotor_tm_msgs__srv__Vec4_Request__fini(message_memory);
}

size_t rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__size_function__Vec4_Request__goal(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__get_const_function__Vec4_Request__goal(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__get_function__Vec4_Request__goal(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__fetch_function__Vec4_Request__goal(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__get_const_function__Vec4_Request__goal(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__assign_function__Vec4_Request__goal(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__get_function__Vec4_Request__goal(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_member_array[1] = {
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__srv__Vec4_Request, goal),  // bytes offset in struct
    NULL,  // default value
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__size_function__Vec4_Request__goal,  // size() function pointer
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__get_const_function__Vec4_Request__goal,  // get_const(index) function pointer
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__get_function__Vec4_Request__goal,  // get(index) function pointer
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__fetch_function__Vec4_Request__goal,  // fetch(index, &value) function pointer
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__assign_function__Vec4_Request__goal,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_members = {
  "rotor_tm_msgs__srv",  // message namespace
  "Vec4_Request",  // message name
  1,  // number of fields
  sizeof(rotor_tm_msgs__srv__Vec4_Request),
  rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_member_array,  // message members
  rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_type_support_handle = {
  0,
  &rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4_Request)() {
  if (!rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__srv__Vec4_Request__rosidl_typesupport_introspection_c__Vec4_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rotor_tm_msgs/srv/detail/vec4__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rotor_tm_msgs/srv/detail/vec4__functions.h"
// already included above
// #include "rotor_tm_msgs/srv/detail/vec4__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rotor_tm_msgs__srv__Vec4_Response__init(message_memory);
}

void rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_fini_function(void * message_memory)
{
  rotor_tm_msgs__srv__Vec4_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__srv__Vec4_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs__srv__Vec4_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_members = {
  "rotor_tm_msgs__srv",  // message namespace
  "Vec4_Response",  // message name
  2,  // number of fields
  sizeof(rotor_tm_msgs__srv__Vec4_Response),
  rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_member_array,  // message members
  rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_type_support_handle = {
  0,
  &rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4_Response)() {
  if (!rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rotor_tm_msgs__srv__Vec4_Response__rosidl_typesupport_introspection_c__Vec4_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rotor_tm_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rotor_tm_msgs/srv/detail/vec4__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_members = {
  "rotor_tm_msgs__srv",  // service namespace
  "Vec4",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_Request_message_type_support_handle,
  NULL  // response message
  // rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_Response_message_type_support_handle
};

static rosidl_service_type_support_t rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_type_support_handle = {
  0,
  &rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rotor_tm_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4)() {
  if (!rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_type_support_handle.typesupport_identifier) {
    rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, srv, Vec4_Response)()->data;
  }

  return &rotor_tm_msgs__srv__detail__vec4__rosidl_typesupport_introspection_c__Vec4_service_type_support_handle;
}