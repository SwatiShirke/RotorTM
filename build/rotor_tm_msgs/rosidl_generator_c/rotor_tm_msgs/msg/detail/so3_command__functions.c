// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rotor_tm_msgs:msg/SO3Command.idl
// generated code does not contain a copyright notice
#include "rotor_tm_msgs/msg/detail/so3_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `force`
// Member `angular_velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"

bool
rotor_tm_msgs__msg__SO3Command__init(rotor_tm_msgs__msg__SO3Command * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rotor_tm_msgs__msg__SO3Command__fini(msg);
    return false;
  }
  // force
  if (!geometry_msgs__msg__Vector3__init(&msg->force)) {
    rotor_tm_msgs__msg__SO3Command__fini(msg);
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__init(&msg->orientation)) {
    rotor_tm_msgs__msg__SO3Command__fini(msg);
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->angular_velocity)) {
    rotor_tm_msgs__msg__SO3Command__fini(msg);
    return false;
  }
  // k_r
  // k_om
  return true;
}

void
rotor_tm_msgs__msg__SO3Command__fini(rotor_tm_msgs__msg__SO3Command * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // force
  geometry_msgs__msg__Vector3__fini(&msg->force);
  // orientation
  geometry_msgs__msg__Quaternion__fini(&msg->orientation);
  // angular_velocity
  geometry_msgs__msg__Vector3__fini(&msg->angular_velocity);
  // k_r
  // k_om
}

bool
rotor_tm_msgs__msg__SO3Command__are_equal(const rotor_tm_msgs__msg__SO3Command * lhs, const rotor_tm_msgs__msg__SO3Command * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // force
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->force), &(rhs->force)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->orientation), &(rhs->orientation)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->angular_velocity), &(rhs->angular_velocity)))
  {
    return false;
  }
  // k_r
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->k_r[i] != rhs->k_r[i]) {
      return false;
    }
  }
  // k_om
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->k_om[i] != rhs->k_om[i]) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__msg__SO3Command__copy(
  const rotor_tm_msgs__msg__SO3Command * input,
  rotor_tm_msgs__msg__SO3Command * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // force
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->force), &(output->force)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->orientation), &(output->orientation)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->angular_velocity), &(output->angular_velocity)))
  {
    return false;
  }
  // k_r
  for (size_t i = 0; i < 3; ++i) {
    output->k_r[i] = input->k_r[i];
  }
  // k_om
  for (size_t i = 0; i < 3; ++i) {
    output->k_om[i] = input->k_om[i];
  }
  return true;
}

rotor_tm_msgs__msg__SO3Command *
rotor_tm_msgs__msg__SO3Command__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__SO3Command * msg = (rotor_tm_msgs__msg__SO3Command *)allocator.allocate(sizeof(rotor_tm_msgs__msg__SO3Command), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rotor_tm_msgs__msg__SO3Command));
  bool success = rotor_tm_msgs__msg__SO3Command__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rotor_tm_msgs__msg__SO3Command__destroy(rotor_tm_msgs__msg__SO3Command * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rotor_tm_msgs__msg__SO3Command__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rotor_tm_msgs__msg__SO3Command__Sequence__init(rotor_tm_msgs__msg__SO3Command__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__SO3Command * data = NULL;

  if (size) {
    data = (rotor_tm_msgs__msg__SO3Command *)allocator.zero_allocate(size, sizeof(rotor_tm_msgs__msg__SO3Command), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rotor_tm_msgs__msg__SO3Command__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rotor_tm_msgs__msg__SO3Command__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rotor_tm_msgs__msg__SO3Command__Sequence__fini(rotor_tm_msgs__msg__SO3Command__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rotor_tm_msgs__msg__SO3Command__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rotor_tm_msgs__msg__SO3Command__Sequence *
rotor_tm_msgs__msg__SO3Command__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__SO3Command__Sequence * array = (rotor_tm_msgs__msg__SO3Command__Sequence *)allocator.allocate(sizeof(rotor_tm_msgs__msg__SO3Command__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rotor_tm_msgs__msg__SO3Command__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rotor_tm_msgs__msg__SO3Command__Sequence__destroy(rotor_tm_msgs__msg__SO3Command__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rotor_tm_msgs__msg__SO3Command__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rotor_tm_msgs__msg__SO3Command__Sequence__are_equal(const rotor_tm_msgs__msg__SO3Command__Sequence * lhs, const rotor_tm_msgs__msg__SO3Command__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rotor_tm_msgs__msg__SO3Command__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__msg__SO3Command__Sequence__copy(
  const rotor_tm_msgs__msg__SO3Command__Sequence * input,
  rotor_tm_msgs__msg__SO3Command__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rotor_tm_msgs__msg__SO3Command);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rotor_tm_msgs__msg__SO3Command * data =
      (rotor_tm_msgs__msg__SO3Command *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rotor_tm_msgs__msg__SO3Command__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rotor_tm_msgs__msg__SO3Command__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rotor_tm_msgs__msg__SO3Command__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
