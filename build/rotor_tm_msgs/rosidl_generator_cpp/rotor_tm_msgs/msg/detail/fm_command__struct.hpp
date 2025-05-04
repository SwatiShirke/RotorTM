// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:msg/FMCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__STRUCT_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__STRUCT_HPP_

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
// Member 'rlink_thrust'
// Member 'moments'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__msg__FMCommand __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__msg__FMCommand __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FMCommand_
{
  using Type = FMCommand_<ContainerAllocator>;

  explicit FMCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    rlink_thrust(_init),
    moments(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->thrust = 0.0;
    }
  }

  explicit FMCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    rlink_thrust(_alloc, _init),
    moments(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->thrust = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _thrust_type =
    double;
  _thrust_type thrust;
  using _rlink_thrust_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _rlink_thrust_type rlink_thrust;
  using _moments_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _moments_type moments;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__thrust(
    const double & _arg)
  {
    this->thrust = _arg;
    return *this;
  }
  Type & set__rlink_thrust(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->rlink_thrust = _arg;
    return *this;
  }
  Type & set__moments(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->moments = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::msg::FMCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::msg::FMCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::FMCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::FMCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__msg__FMCommand
    std::shared_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__msg__FMCommand
    std::shared_ptr<rotor_tm_msgs::msg::FMCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FMCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->thrust != other.thrust) {
      return false;
    }
    if (this->rlink_thrust != other.rlink_thrust) {
      return false;
    }
    if (this->moments != other.moments) {
      return false;
    }
    return true;
  }
  bool operator!=(const FMCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FMCommand_

// alias to use template instance with default allocator
using FMCommand =
  rotor_tm_msgs::msg::FMCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FM_COMMAND__STRUCT_HPP_
