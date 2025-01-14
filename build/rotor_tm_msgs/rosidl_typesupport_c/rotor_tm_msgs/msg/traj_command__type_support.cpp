// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from rotor_tm_msgs:msg/TrajCommand.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rotor_tm_msgs/msg/detail/traj_command__struct.h"
#include "rotor_tm_msgs/msg/detail/traj_command__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rotor_tm_msgs
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _TrajCommand_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TrajCommand_type_support_ids_t;

static const _TrajCommand_type_support_ids_t _TrajCommand_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _TrajCommand_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TrajCommand_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TrajCommand_type_support_symbol_names_t _TrajCommand_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rotor_tm_msgs, msg, TrajCommand)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rotor_tm_msgs, msg, TrajCommand)),
  }
};

typedef struct _TrajCommand_type_support_data_t
{
  void * data[2];
} _TrajCommand_type_support_data_t;

static _TrajCommand_type_support_data_t _TrajCommand_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TrajCommand_message_typesupport_map = {
  2,
  "rotor_tm_msgs",
  &_TrajCommand_message_typesupport_ids.typesupport_identifier[0],
  &_TrajCommand_message_typesupport_symbol_names.symbol_name[0],
  &_TrajCommand_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TrajCommand_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TrajCommand_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace rotor_tm_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rotor_tm_msgs, msg, TrajCommand)() {
  return &::rotor_tm_msgs::msg::rosidl_typesupport_c::TrajCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
