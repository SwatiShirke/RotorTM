// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rotor_tm_msgs:msg/RPMCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rotor_tm_msgs/msg/detail/rpm_command__struct.hpp"
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

void RPMCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rotor_tm_msgs::msg::RPMCommand(_init);
}

void RPMCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rotor_tm_msgs::msg::RPMCommand *>(message_memory);
  typed_message->~RPMCommand();
}

size_t size_function__RPMCommand__rpms(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__RPMCommand__rpms(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int32_t, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__RPMCommand__rpms(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int32_t, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__RPMCommand__rpms(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__RPMCommand__rpms(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__RPMCommand__rpms(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__RPMCommand__rpms(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RPMCommand_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs::msg::RPMCommand, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rpms",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rotor_tm_msgs::msg::RPMCommand, rpms),  // bytes offset in struct
    nullptr,  // default value
    size_function__RPMCommand__rpms,  // size() function pointer
    get_const_function__RPMCommand__rpms,  // get_const(index) function pointer
    get_function__RPMCommand__rpms,  // get(index) function pointer
    fetch_function__RPMCommand__rpms,  // fetch(index, &value) function pointer
    assign_function__RPMCommand__rpms,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RPMCommand_message_members = {
  "rotor_tm_msgs::msg",  // message namespace
  "RPMCommand",  // message name
  2,  // number of fields
  sizeof(rotor_tm_msgs::msg::RPMCommand),
  RPMCommand_message_member_array,  // message members
  RPMCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  RPMCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RPMCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RPMCommand_message_members,
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
get_message_type_support_handle<rotor_tm_msgs::msg::RPMCommand>()
{
  return &::rotor_tm_msgs::msg::rosidl_typesupport_introspection_cpp::RPMCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rotor_tm_msgs, msg, RPMCommand)() {
  return &::rotor_tm_msgs::msg::rosidl_typesupport_introspection_cpp::RPMCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
