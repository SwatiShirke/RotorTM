// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rotor_tm_msgs:srv/Vec4.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__SRV__DETAIL__VEC4__STRUCT_HPP_
#define ROTOR_TM_MSGS__SRV__DETAIL__VEC4__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__srv__Vec4_Request __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__srv__Vec4_Request __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Vec4_Request_
{
  using Type = Vec4_Request_<ContainerAllocator>;

  explicit Vec4_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->goal.begin(), this->goal.end(), 0.0f);
    }
  }

  explicit Vec4_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->goal.begin(), this->goal.end(), 0.0f);
    }
  }

  // field types and members
  using _goal_type =
    std::array<float, 4>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal(
    const std::array<float, 4> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__srv__Vec4_Request
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__srv__Vec4_Request
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vec4_Request_ & other) const
  {
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vec4_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vec4_Request_

// alias to use template instance with default allocator
using Vec4_Request =
  rotor_tm_msgs::srv::Vec4_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rotor_tm_msgs


#ifndef _WIN32
# define DEPRECATED__rotor_tm_msgs__srv__Vec4_Response __attribute__((deprecated))
#else
# define DEPRECATED__rotor_tm_msgs__srv__Vec4_Response __declspec(deprecated)
#endif

namespace rotor_tm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Vec4_Response_
{
  using Type = Vec4_Response_<ContainerAllocator>;

  explicit Vec4_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit Vec4_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rotor_tm_msgs__srv__Vec4_Response
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rotor_tm_msgs__srv__Vec4_Response
    std::shared_ptr<rotor_tm_msgs::srv::Vec4_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vec4_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vec4_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vec4_Response_

// alias to use template instance with default allocator
using Vec4_Response =
  rotor_tm_msgs::srv::Vec4_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rotor_tm_msgs

namespace rotor_tm_msgs
{

namespace srv
{

struct Vec4
{
  using Request = rotor_tm_msgs::srv::Vec4_Request;
  using Response = rotor_tm_msgs::srv::Vec4_Response;
};

}  // namespace srv

}  // namespace rotor_tm_msgs

#endif  // ROTOR_TM_MSGS__SRV__DETAIL__VEC4__STRUCT_HPP_
