// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:msg/FMNCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__STRUCT_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__STRUCT_HPP_

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
// Member 'null_space_vec'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__msg__FMNCommand __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__msg__FMNCommand __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FMNCommand_
{
  using Type = FMNCommand_<ContainerAllocator>;

  explicit FMNCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    rlink_thrust(_init),
    moments(_init),
    null_space_vec(_init)
  {
    (void)_init;
  }

  explicit FMNCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    rlink_thrust(_alloc, _init),
    moments(_alloc, _init),
    null_space_vec(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _rlink_thrust_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _rlink_thrust_type rlink_thrust;
  using _moments_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _moments_type moments;
  using _null_space_vec_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _null_space_vec_type null_space_vec;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
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
  Type & set__null_space_vec(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->null_space_vec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__msg__FMNCommand
    std::shared_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__msg__FMNCommand
    std::shared_ptr<rotor_tm_msgs::msg::FMNCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FMNCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->rlink_thrust != other.rlink_thrust) {
      return false;
    }
    if (this->moments != other.moments) {
      return false;
    }
    if (this->null_space_vec != other.null_space_vec) {
      return false;
    }
    return true;
  }
  bool operator!=(const FMNCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FMNCommand_

// alias to use template instance with default allocator
using FMNCommand =
  rotor_tm_msgs::msg::FMNCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__FMN_COMMAND__STRUCT_HPP_
