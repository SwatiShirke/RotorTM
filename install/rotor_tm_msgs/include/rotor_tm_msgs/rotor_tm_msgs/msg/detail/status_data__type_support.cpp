// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rotor_tm_msgs:msg/StatusData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rotor_tm_msgs/msg/detail/status_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rotor_tm_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void StatusData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rotor_tm_msgs::msg::StatusData(_init);
}

void StatusData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rotor_tm_msgs::msg::StatusData *>(message_memory);
  typed_message->~StatusData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember StatusData_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs::msg::StatusData, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::String>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs::msg::StatusData, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers StatusData_message_members = {
  "rotor_tm_msgs::msg",  // message namespace
  "StatusData",  // message name
  2,  // number of fields
  sizeof(rotor_tm_msgs::msg::StatusData),
  StatusData_message_member_array,  // message members
  StatusData_init_function,  // function to initialize message memory (memory has to be allocated)
  StatusData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t StatusData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &StatusData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rotor_tm_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rotor_tm_msgs::msg::StatusData>()
{
  return &::rotor_tm_msgs::msg::rosidl_typesupport_introspection_cpp::StatusData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rotor_tm_msgs, msg, StatusData)() {
  return &::rotor_tm_msgs::msg::rosidl_typesupport_introspection_cpp::StatusData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
