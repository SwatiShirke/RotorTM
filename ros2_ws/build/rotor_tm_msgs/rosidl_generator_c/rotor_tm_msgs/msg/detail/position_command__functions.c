// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rotor_tm_msgs:msg/PositionCommand.idl
// generated code does not contain a copyright notice
#include "rotor_tm_msgs/msg/detail/position_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `velocity`
// Member `acceleration`
// Member `jerk`
// Member `angular_velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__functions.h"

bool
rotor_tm_msgs__msg__PositionCommand__init(rotor_tm_msgs__msg__PositionCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->velocity)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->acceleration)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // jerk
  if (!geometry_msgs__msg__Vector3__init(&msg->jerk)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__init(&msg->quaternion)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->angular_velocity)) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
    return false;
  }
  // kx
  // kv
  return true;
}

void
rotor_tm_msgs__msg__PositionCommand__fini(rotor_tm_msgs__msg__PositionCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // velocity
  geometry_msgs__msg__Vector3__fini(&msg->velocity);
  // acceleration
  geometry_msgs__msg__Vector3__fini(&msg->acceleration);
  // jerk
  geometry_msgs__msg__Vector3__fini(&msg->jerk);
  // quaternion
  geometry_msgs__msg__Quaternion__fini(&msg->quaternion);
  // angular_velocity
  geometry_msgs__msg__Vector3__fini(&msg->angular_velocity);
  // kx
  // kv
}

bool
rotor_tm_msgs__msg__PositionCommand__are_equal(const rotor_tm_msgs__msg__PositionCommand * lhs, const rotor_tm_msgs__msg__PositionCommand * rhs)
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
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->acceleration), &(rhs->acceleration)))
  {
    return false;
  }
  // jerk
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->jerk), &(rhs->jerk)))
  {
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->quaternion), &(rhs->quaternion)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->angular_velocity), &(rhs->angular_velocity)))
  {
    return false;
  }
  // kx
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->kx[i] != rhs->kx[i]) {
      return false;
    }
  }
  // kv
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->kv[i] != rhs->kv[i]) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__msg__PositionCommand__copy(
  const rotor_tm_msgs__msg__PositionCommand * input,
  rotor_tm_msgs__msg__PositionCommand * output)
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
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->acceleration), &(output->acceleration)))
  {
    return false;
  }
  // jerk
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->jerk), &(output->jerk)))
  {
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->quaternion), &(output->quaternion)))
  {
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->angular_velocity), &(output->angular_velocity)))
  {
    return false;
  }
  // kx
  for (size_t i = 0; i < 3; ++i) {
    output->kx[i] = input->kx[i];
  }
  // kv
  for (size_t i = 0; i < 3; ++i) {
    output->kv[i] = input->kv[i];
  }
  return true;
}

rotor_tm_msgs__msg__PositionCommand *
rotor_tm_msgs__msg__PositionCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__PositionCommand * msg = (rotor_tm_msgs__msg__PositionCommand *)allocator.allocate(sizeof(rotor_tm_msgs__msg__PositionCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rotor_tm_msgs__msg__PositionCommand));
  bool success = rotor_tm_msgs__msg__PositionCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rotor_tm_msgs__msg__PositionCommand__destroy(rotor_tm_msgs__msg__PositionCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rotor_tm_msgs__msg__PositionCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rotor_tm_msgs__msg__PositionCommand__Sequence__init(rotor_tm_msgs__msg__PositionCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__PositionCommand * data = NULL;

  if (size) {
    data = (rotor_tm_msgs__msg__PositionCommand *)allocator.zero_allocate(size, sizeof(rotor_tm_msgs__msg__PositionCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rotor_tm_msgs__msg__PositionCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rotor_tm_msgs__msg__PositionCommand__fini(&data[i - 1]);
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
rotor_tm_msgs__msg__PositionCommand__Sequence__fini(rotor_tm_msgs__msg__PositionCommand__Sequence * array)
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
      rotor_tm_msgs__msg__PositionCommand__fini(&array->data[i]);
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

rotor_tm_msgs__msg__PositionCommand__Sequence *
rotor_tm_msgs__msg__PositionCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__PositionCommand__Sequence * array = (rotor_tm_msgs__msg__PositionCommand__Sequence *)allocator.allocate(sizeof(rotor_tm_msgs__msg__PositionCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rotor_tm_msgs__msg__PositionCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rotor_tm_msgs__msg__PositionCommand__Sequence__destroy(rotor_tm_msgs__msg__PositionCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rotor_tm_msgs__msg__PositionCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rotor_tm_msgs__msg__PositionCommand__Sequence__are_equal(const rotor_tm_msgs__msg__PositionCommand__Sequence * lhs, const rotor_tm_msgs__msg__PositionCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rotor_tm_msgs__msg__PositionCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__msg__PositionCommand__Sequence__copy(
  const rotor_tm_msgs__msg__PositionCommand__Sequence * input,
  rotor_tm_msgs__msg__PositionCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rotor_tm_msgs__msg__PositionCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rotor_tm_msgs__msg__PositionCommand * data =
      (rotor_tm_msgs__msg__PositionCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rotor_tm_msgs__msg__PositionCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rotor_tm_msgs__msg__PositionCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rotor_tm_msgs__msg__PositionCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
