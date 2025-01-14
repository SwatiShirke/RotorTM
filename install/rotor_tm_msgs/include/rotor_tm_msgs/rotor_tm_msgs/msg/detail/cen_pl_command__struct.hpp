// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:msg/CenPLCommand.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__STRUCT_HPP_
#define ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__STRUCT_HPP_

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
// Member 'pos_cmd'
#include "rotor_tm_msgs/msg/detail/position_command__struct.hpp"
// Member 'acc'
// Member 'estimated_acc'
// Member 'mu'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__msg__CenPLCommand __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__msg__CenPLCommand __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CenPLCommand_
{
  using Type = CenPLCommand_<ContainerAllocator>;

  explicit CenPLCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pos_cmd(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->copr_status = 0;
    }
  }

  explicit CenPLCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pos_cmd(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->copr_status = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pos_cmd_type =
    rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator>;
  _pos_cmd_type pos_cmd;
  using _acc_type =
    std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Vector3_<ContainerAllocator>>>;
  _acc_type acc;
  using _estimated_acc_type =
    std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Vector3_<ContainerAllocator>>>;
  _estimated_acc_type estimated_acc;
  using _mu_type =
    std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Vector3_<ContainerAllocator>>>;
  _mu_type mu;
  using _copr_status_type =
    uint8_t;
  _copr_status_type copr_status;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pos_cmd(
    const rotor_tm_msgs::msg::PositionCommand_<ContainerAllocator> & _arg)
  {
    this->pos_cmd = _arg;
    return *this;
  }
  Type & set__acc(
    const std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Vector3_<ContainerAllocator>>> & _arg)
  {
    this->acc = _arg;
    return *this;
  }
  Type & set__estimated_acc(
    const std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Vector3_<ContainerAllocator>>> & _arg)
  {
    this->estimated_acc = _arg;
    return *this;
  }
  Type & set__mu(
    const std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Vector3_<ContainerAllocator>>> & _arg)
  {
    this->mu = _arg;
    return *this;
  }
  Type & set__copr_status(
    const uint8_t & _arg)
  {
    this->copr_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__msg__CenPLCommand
    std::shared_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__msg__CenPLCommand
    std::shared_ptr<rotor_tm_msgs::msg::CenPLCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CenPLCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pos_cmd != other.pos_cmd) {
      return false;
    }
    if (this->acc != other.acc) {
      return false;
    }
    if (this->estimated_acc != other.estimated_acc) {
      return false;
    }
    if (this->mu != other.mu) {
      return false;
    }
    if (this->copr_status != other.copr_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const CenPLCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CenPLCommand_

// alias to use template instance with default allocator
using CenPLCommand =
  rotor_tm_msgs::msg::CenPLCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__CEN_PL_COMMAND__STRUCT_HPP_
