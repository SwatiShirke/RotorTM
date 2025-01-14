// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rotor_tm_msgs:msg/SO3Command.idl
// generated code does not contain a copyright notice

#ifndef ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__FUNCTIONS_H_
#define ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rotor_tm_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rotor_tm_msgs/msg/detail/so3_command__struct.h"

/// Initialize msg/SO3Command message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rotor_tm_msgs__msg__SO3Command
 * )) before or use
 * rotor_tm_msgs__msg__SO3Command__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
bool
rotor_tm_msgs__msg__SO3Command__init(rotor_tm_msgs__msg__SO3Command * msg);

/// Finalize msg/SO3Command message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
void
rotor_tm_msgs__msg__SO3Command__fini(rotor_tm_msgs__msg__SO3Command * msg);

/// Create msg/SO3Command message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rotor_tm_msgs__msg__SO3Command__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
rotor_tm_msgs__msg__SO3Command *
rotor_tm_msgs__msg__SO3Command__create();

/// Destroy msg/SO3Command message.
/**
 * It calls
 * rotor_tm_msgs__msg__SO3Command__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
void
rotor_tm_msgs__msg__SO3Command__destroy(rotor_tm_msgs__msg__SO3Command * msg);

/// Check for msg/SO3Command message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
bool
rotor_tm_msgs__msg__SO3Command__are_equal(const rotor_tm_msgs__msg__SO3Command * lhs, const rotor_tm_msgs__msg__SO3Command * rhs);

/// Copy a msg/SO3Command message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
bool
rotor_tm_msgs__msg__SO3Command__copy(
  const rotor_tm_msgs__msg__SO3Command * input,
  rotor_tm_msgs__msg__SO3Command * output);

/// Initialize array of msg/SO3Command messages.
/**
 * It allocates the memory for the number of elements and calls
 * rotor_tm_msgs__msg__SO3Command__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
bool
rotor_tm_msgs__msg__SO3Command__Sequence__init(rotor_tm_msgs__msg__SO3Command__Sequence * array, size_t size);

/// Finalize array of msg/SO3Command messages.
/**
 * It calls
 * rotor_tm_msgs__msg__SO3Command__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
void
rotor_tm_msgs__msg__SO3Command__Sequence__fini(rotor_tm_msgs__msg__SO3Command__Sequence * array);

/// Create array of msg/SO3Command messages.
/**
 * It allocates the memory for the array and calls
 * rotor_tm_msgs__msg__SO3Command__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
rotor_tm_msgs__msg__SO3Command__Sequence *
rotor_tm_msgs__msg__SO3Command__Sequence__create(size_t size);

/// Destroy array of msg/SO3Command messages.
/**
 * It calls
 * rotor_tm_msgs__msg__SO3Command__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
void
rotor_tm_msgs__msg__SO3Command__Sequence__destroy(rotor_tm_msgs__msg__SO3Command__Sequence * array);

/// Check for msg/SO3Command message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
bool
rotor_tm_msgs__msg__SO3Command__Sequence__are_equal(const rotor_tm_msgs__msg__SO3Command__Sequence * lhs, const rotor_tm_msgs__msg__SO3Command__Sequence * rhs);

/// Copy an array of msg/SO3Command messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rotor_tm_msgs
bool
rotor_tm_msgs__msg__SO3Command__Sequence__copy(
  const rotor_tm_msgs__msg__SO3Command__Sequence * input,
  rotor_tm_msgs__msg__SO3Command__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROTOR_TM_MSGS__MSG__DETAIL__SO3_COMMAND__FUNCTIONS_H_
