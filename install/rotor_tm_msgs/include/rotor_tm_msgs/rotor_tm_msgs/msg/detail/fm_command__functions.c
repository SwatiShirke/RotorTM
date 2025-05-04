// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rotor_tm_msgs:msg/FMCommand.idl
// generated code does not contain a copyright notice
#include "rotor_tm_msgs/msg/detail/fm_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `rlink_thrust`
// Member `moments`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
rotor_tm_msgs__msg__FMCommand__init(rotor_tm_msgs__msg__FMCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rotor_tm_msgs__msg__FMCommand__fini(msg);
    return false;
  }
  // thrust
  // rlink_thrust
  if (!geometry_msgs__msg__Vector3__init(&msg->rlink_thrust)) {
    rotor_tm_msgs__msg__FMCommand__fini(msg);
    return false;
  }
  // moments
  if (!geometry_msgs__msg__Vector3__init(&msg->moments)) {
    rotor_tm_msgs__msg__FMCommand__fini(msg);
    return false;
  }
  return true;
}

void
rotor_tm_msgs__msg__FMCommand__fini(rotor_tm_msgs__msg__FMCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // thrust
  // rlink_thrust
  geometry_msgs__msg__Vector3__fini(&msg->rlink_thrust);
  // moments
  geometry_msgs__msg__Vector3__fini(&msg->moments);
}

bool
rotor_tm_msgs__msg__FMCommand__are_equal(const rotor_tm_msgs__msg__FMCommand * lhs, const rotor_tm_msgs__msg__FMCommand * rhs)
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
  // thrust
  if (lhs->thrust != rhs->thrust) {
    return false;
  }
  // rlink_thrust
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->rlink_thrust), &(rhs->rlink_thrust)))
  {
    return false;
  }
  // moments
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->moments), &(rhs->moments)))
  {
    return false;
  }
  return true;
}

bool
rotor_tm_msgs__msg__FMCommand__copy(
  const rotor_tm_msgs__msg__FMCommand * input,
  rotor_tm_msgs__msg__FMCommand * output)
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
  // thrust
  output->thrust = input->thrust;
  // rlink_thrust
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->rlink_thrust), &(output->rlink_thrust)))
  {
    return false;
  }
  // moments
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->moments), &(output->moments)))
  {
    return false;
  }
  return true;
}

rotor_tm_msgs__msg__FMCommand *
rotor_tm_msgs__msg__FMCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__FMCommand * msg = (rotor_tm_msgs__msg__FMCommand *)allocator.allocate(sizeof(rotor_tm_msgs__msg__FMCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rotor_tm_msgs__msg__FMCommand));
  bool success = rotor_tm_msgs__msg__FMCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rotor_tm_msgs__msg__FMCommand__destroy(rotor_tm_msgs__msg__FMCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rotor_tm_msgs__msg__FMCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rotor_tm_msgs__msg__FMCommand__Sequence__init(rotor_tm_msgs__msg__FMCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__FMCommand * data = NULL;

  if (size) {
    data = (rotor_tm_msgs__msg__FMCommand *)allocator.zero_allocate(size, sizeof(rotor_tm_msgs__msg__FMCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rotor_tm_msgs__msg__FMCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rotor_tm_msgs__msg__FMCommand__fini(&data[i - 1]);
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
rotor_tm_msgs__msg__FMCommand__Sequence__fini(rotor_tm_msgs__msg__FMCommand__Sequence * array)
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
      rotor_tm_msgs__msg__FMCommand__fini(&array->data[i]);
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

rotor_tm_msgs__msg__FMCommand__Sequence *
rotor_tm_msgs__msg__FMCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__msg__FMCommand__Sequence * array = (rotor_tm_msgs__msg__FMCommand__Sequence *)allocator.allocate(sizeof(rotor_tm_msgs__msg__FMCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rotor_tm_msgs__msg__FMCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rotor_tm_msgs__msg__FMCommand__Sequence__destroy(rotor_tm_msgs__msg__FMCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rotor_tm_msgs__msg__FMCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rotor_tm_msgs__msg__FMCommand__Sequence__are_equal(const rotor_tm_msgs__msg__FMCommand__Sequence * lhs, const rotor_tm_msgs__msg__FMCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rotor_tm_msgs__msg__FMCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__msg__FMCommand__Sequence__copy(
  const rotor_tm_msgs__msg__FMCommand__Sequence * input,
  rotor_tm_msgs__msg__FMCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rotor_tm_msgs__msg__FMCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rotor_tm_msgs__msg__FMCommand * data =
      (rotor_tm_msgs__msg__FMCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rotor_tm_msgs__msg__FMCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rotor_tm_msgs__msg__FMCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rotor_tm_msgs__msg__FMCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
