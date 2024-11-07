// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:msg/StatusData.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__STRUCT_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'status'
#include "std_msgs/msg/detail/string__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__msg__StatusData __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__msg__StatusData __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StatusData_
{
  using Type = StatusData_<ContainerAllocator>;

  explicit StatusData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    status(_init)
  {
    (void)_init;
  }

  explicit StatusData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    status(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _status_type =
    std_msgs::msg::String_<ContainerAllocator>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__status(
    const std_msgs::msg::String_<ContainerAllocator> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::msg::StatusData_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::msg::StatusData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::StatusData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::StatusData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__msg__StatusData
    std::shared_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__msg__StatusData
    std::shared_ptr<rotor_tm_msgs::msg::StatusData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StatusData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const StatusData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StatusData_

// alias to use template instance with default allocator
using StatusData =
  rotor_tm_msgs::msg::StatusData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__STATUS_DATA__STRUCT_HPP_
