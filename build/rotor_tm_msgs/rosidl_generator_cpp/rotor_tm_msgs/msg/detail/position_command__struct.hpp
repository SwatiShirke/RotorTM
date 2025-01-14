// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:msg/PositionCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__STRUCT_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__STRUCT_HPP_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'velocity'
// Member 'acceleration'
// Member 'jerk'
// Member 'angular_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__msg__PositionCommand __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__msg__PositionCommand __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PositionCommand_
{
  using Type = PositionCommand_<ContainerAllocator>;

  explicit PositionCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init),
    velocity(_init),
    acceleration(_init),
    jerk(_init),
    quaternion(_init),
    angular_velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->kx.begin(), this->kx.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->kv.begin(), this->kv.end(), 0.0);
    }
  }

  explicit PositionCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position(_alloc, _init),
    velocity(_alloc, _init),
    acceleration(_alloc, _init),
    jerk(_alloc, _init),
    quaternion(_alloc, _init),
    angular_velocity(_alloc, _init),
    kx(_alloc),
    kv(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 3>::iterator, double>(this->kx.begin(), this->kx.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->kv.begin(), this->kv.end(), 0.0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;
  using _acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _acceleration_type acceleration;
  using _jerk_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _jerk_type jerk;
  using _quaternion_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _quaternion_type quaternion;
  using _angular_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _angular_velocity_type angular_velocity;
  using _kx_type =
    std::array<double, 3>;
  _kx_type kx;
  using _kv_type =
    std::array<double, 3>;
  _kv_type kv;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__jerk(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->jerk = _arg;
    return *this;
  }
  Type & set__quaternion(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->quaternion = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }
  Type & set__kx(
    const std::array<double, 3> & _arg)
  {
    this->kx = _arg;
    return *this;
  }
  Type & set__kv(
    const std::array<double, 3> & _arg)
  {
    this->kv = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__msg__PositionCommand
    std::shared_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__msg__PositionCommand
    std::shared_ptr<rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PositionCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->jerk != other.jerk) {
      return false;
    }
    if (this->quaternion != other.quaternion) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    if (this->kx != other.kx) {
      return false;
    }
    if (this->kv != other.kv) {
      return false;
    }
    return true;
  }
  bool operator!=(const PositionCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PositionCommand_

// alias to use template instance with default allocator
using PositionCommand =
  rotor_tm_msgs::msg::PositionCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__POSITION_COMMAND__STRUCT_HPP_
