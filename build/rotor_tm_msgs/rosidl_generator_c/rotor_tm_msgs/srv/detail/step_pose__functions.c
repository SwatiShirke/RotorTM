// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rotor_tm_msgs:srv/StepPose.idl
// generated code does not contain a copyright notice
#include "rotor_tm_msgs/srv/detail/step_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
rotor_tm_msgs__srv__StepPose_Request__init(rotor_tm_msgs__srv__StepPose_Request * msg)
{
  if (!msg) {
    return false;
  }
  // position
  // roll
  // pitch
  // yaw
  return true;
}

void
rotor_tm_msgs__srv__StepPose_Request__fini(rotor_tm_msgs__srv__StepPose_Request * msg)
{
  if (!msg) {
    return;
  }
  // position
  // roll
  // pitch
  // yaw
}

bool
rotor_tm_msgs__srv__StepPose_Request__are_equal(const rotor_tm_msgs__srv__StepPose_Request * lhs, const rotor_tm_msgs__srv__StepPose_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->position[i] != rhs->position[i]) {
      return false;
    }
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
rotor_tm_msgs__srv__StepPose_Request__copy(
  const rotor_tm_msgs__srv__StepPose_Request * input,
  rotor_tm_msgs__srv__StepPose_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  for (size_t i = 0; i < 3; ++i) {
    output->position[i] = input->position[i];
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

rotor_tm_msgs__srv__StepPose_Request *
rotor_tm_msgs__srv__StepPose_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__srv__StepPose_Request * msg = (rotor_tm_msgs__srv__StepPose_Request *)allocator.allocate(sizeof(rotor_tm_msgs__srv__StepPose_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rotor_tm_msgs__srv__StepPose_Request));
  bool success = rotor_tm_msgs__srv__StepPose_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rotor_tm_msgs__srv__StepPose_Request__destroy(rotor_tm_msgs__srv__StepPose_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rotor_tm_msgs__srv__StepPose_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rotor_tm_msgs__srv__StepPose_Request__Sequence__init(rotor_tm_msgs__srv__StepPose_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__srv__StepPose_Request * data = NULL;

  if (size) {
    data = (rotor_tm_msgs__srv__StepPose_Request *)allocator.zero_allocate(size, sizeof(rotor_tm_msgs__srv__StepPose_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rotor_tm_msgs__srv__StepPose_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rotor_tm_msgs__srv__StepPose_Request__fini(&data[i - 1]);
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
rotor_tm_msgs__srv__StepPose_Request__Sequence__fini(rotor_tm_msgs__srv__StepPose_Request__Sequence * array)
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
      rotor_tm_msgs__srv__StepPose_Request__fini(&array->data[i]);
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

rotor_tm_msgs__srv__StepPose_Request__Sequence *
rotor_tm_msgs__srv__StepPose_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__srv__StepPose_Request__Sequence * array = (rotor_tm_msgs__srv__StepPose_Request__Sequence *)allocator.allocate(sizeof(rotor_tm_msgs__srv__StepPose_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rotor_tm_msgs__srv__StepPose_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rotor_tm_msgs__srv__StepPose_Request__Sequence__destroy(rotor_tm_msgs__srv__StepPose_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rotor_tm_msgs__srv__StepPose_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rotor_tm_msgs__srv__StepPose_Request__Sequence__are_equal(const rotor_tm_msgs__srv__StepPose_Request__Sequence * lhs, const rotor_tm_msgs__srv__StepPose_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rotor_tm_msgs__srv__StepPose_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__srv__StepPose_Request__Sequence__copy(
  const rotor_tm_msgs__srv__StepPose_Request__Sequence * input,
  rotor_tm_msgs__srv__StepPose_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rotor_tm_msgs__srv__StepPose_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rotor_tm_msgs__srv__StepPose_Request * data =
      (rotor_tm_msgs__srv__StepPose_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rotor_tm_msgs__srv__StepPose_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rotor_tm_msgs__srv__StepPose_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rotor_tm_msgs__srv__StepPose_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
rotor_tm_msgs__srv__StepPose_Response__init(rotor_tm_msgs__srv__StepPose_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    rotor_tm_msgs__srv__StepPose_Response__fini(msg);
    return false;
  }
  return true;
}

void
rotor_tm_msgs__srv__StepPose_Response__fini(rotor_tm_msgs__srv__StepPose_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
rotor_tm_msgs__srv__StepPose_Response__are_equal(const rotor_tm_msgs__srv__StepPose_Response * lhs, const rotor_tm_msgs__srv__StepPose_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
rotor_tm_msgs__srv__StepPose_Response__copy(
  const rotor_tm_msgs__srv__StepPose_Response * input,
  rotor_tm_msgs__srv__StepPose_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

rotor_tm_msgs__srv__StepPose_Response *
rotor_tm_msgs__srv__StepPose_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__srv__StepPose_Response * msg = (rotor_tm_msgs__srv__StepPose_Response *)allocator.allocate(sizeof(rotor_tm_msgs__srv__StepPose_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rotor_tm_msgs__srv__StepPose_Response));
  bool success = rotor_tm_msgs__srv__StepPose_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rotor_tm_msgs__srv__StepPose_Response__destroy(rotor_tm_msgs__srv__StepPose_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rotor_tm_msgs__srv__StepPose_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rotor_tm_msgs__srv__StepPose_Response__Sequence__init(rotor_tm_msgs__srv__StepPose_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__srv__StepPose_Response * data = NULL;

  if (size) {
    data = (rotor_tm_msgs__srv__StepPose_Response *)allocator.zero_allocate(size, sizeof(rotor_tm_msgs__srv__StepPose_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rotor_tm_msgs__srv__StepPose_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rotor_tm_msgs__srv__StepPose_Response__fini(&data[i - 1]);
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
rotor_tm_msgs__srv__StepPose_Response__Sequence__fini(rotor_tm_msgs__srv__StepPose_Response__Sequence * array)
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
      rotor_tm_msgs__srv__StepPose_Response__fini(&array->data[i]);
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

rotor_tm_msgs__srv__StepPose_Response__Sequence *
rotor_tm_msgs__srv__StepPose_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rotor_tm_msgs__srv__StepPose_Response__Sequence * array = (rotor_tm_msgs__srv__StepPose_Response__Sequence *)allocator.allocate(sizeof(rotor_tm_msgs__srv__StepPose_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rotor_tm_msgs__srv__StepPose_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rotor_tm_msgs__srv__StepPose_Response__Sequence__destroy(rotor_tm_msgs__srv__StepPose_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rotor_tm_msgs__srv__StepPose_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rotor_tm_msgs__srv__StepPose_Response__Sequence__are_equal(const rotor_tm_msgs__srv__StepPose_Response__Sequence * lhs, const rotor_tm_msgs__srv__StepPose_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rotor_tm_msgs__srv__StepPose_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rotor_tm_msgs__srv__StepPose_Response__Sequence__copy(
  const rotor_tm_msgs__srv__StepPose_Response__Sequence * input,
  rotor_tm_msgs__srv__StepPose_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rotor_tm_msgs__srv__StepPose_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rotor_tm_msgs__srv__StepPose_Response * data =
      (rotor_tm_msgs__srv__StepPose_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rotor_tm_msgs__srv__StepPose_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rotor_tm_msgs__srv__StepPose_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rotor_tm_msgs__srv__StepPose_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
