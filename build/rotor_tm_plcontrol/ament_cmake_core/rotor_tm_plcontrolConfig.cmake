# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rotor_tm_plcontrol_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rotor_tm_plcontrol_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rotor_tm_plcontrol_FOUND FALSE)
  elseif(NOT rotor_tm_plcontrol_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rotor_tm_plcontrol_FOUND FALSE)
  endif()
  return()
endif()
set(_rotor_tm_plcontrol_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rotor_tm_plcontrol_FIND_QUIETLY)
  message(STATUS "Found rotor_tm_plcontrol: 0.0.0 (${rotor_tm_plcontrol_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rotor_tm_plcontrol' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${rotor_tm_plcontrol_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rotor_tm_plcontrol_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${rotor_tm_plcontrol_DIR}/${_extra}")
endforeach()
