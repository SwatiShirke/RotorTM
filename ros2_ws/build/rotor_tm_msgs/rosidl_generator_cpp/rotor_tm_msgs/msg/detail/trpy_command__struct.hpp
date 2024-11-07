// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:msg/TRPYCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__TRPY_COMMAND__STRUCT_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__TRPY_COMMAND__STRUCT_HPP_

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
// Member 'angular_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__msg__TRPYCommand __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__msg__TRPYCommand __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TRPYCommand_
{
  using Type = TRPYCommand_<ContainerAllocator>;

  explicit TRPYCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    angular_velocity(_init),
    quaternion(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->thrust = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      std::fill<typename std::array<double, 3>::iterator, double>(this->k_r.begin(), this->k_r.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->k_om.begin(), this->k_om.end(), 0.0);
    }
  }

  explicit TRPYCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    angular_velocity(_alloc, _init),
    quaternion(_alloc, _init),
    k_r(_alloc),
    k_om(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->thrust = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
      std::fill<typename std::array<double, 3>::iterator, double>(this->k_r.begin(), this->k_r.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->k_om.begin(), this->k_om.end(), 0.0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _thrust_type =
    double;
  _thrust_type thrust;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _angular_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _angular_velocity_type angular_velocity;
  using _quaternion_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _quaternion_type quaternion;
  using _k_r_type =
    std::array<double, 3>;
  _k_r_type k_r;
  using _k_om_type =
    std::array<double, 3>;
  _k_om_type k_om;

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
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }
  Type & set__quaternion(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->quaternion = _arg;
    return *this;
  }
  Type & set__k_r(
    const std::array<double, 3> & _arg)
  {
    this->k_r = _arg;
    return *this;
  }
  Type & set__k_om(
    const std::array<double, 3> & _arg)
  {
    this->k_om = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__msg__TRPYCommand
    std::shared_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__msg__TRPYCommand
    std::shared_ptr<rotor_tm_msgs::msg::TRPYCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TRPYCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->thrust != other.thrust) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    if (this->quaternion != other.quaternion) {
      return false;
    }
    if (this->k_r != other.k_r) {
      return false;
    }
    if (this->k_om != other.k_om) {
      return false;
    }
    return true;
  }
  bool operator!=(const TRPYCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TRPYCommand_

// alias to use template instance with default allocator
using TRPYCommand =
  rotor_tm_msgs::msg::TRPYCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__TRPY_COMMAND__STRUCT_HPP_
