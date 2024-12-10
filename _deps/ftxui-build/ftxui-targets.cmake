# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.29)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS ftxui::screen ftxui::dom ftxui::component)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target ftxui::screen
add_library(ftxui::screen STATIC IMPORTED)

set_target_properties(ftxui::screen PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "/home/hnakamura/vsc_projects/textEditor/_deps/ftxui-src/include"
)

# Create imported target ftxui::dom
add_library(ftxui::dom STATIC IMPORTED)

set_target_properties(ftxui::dom PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "/home/hnakamura/vsc_projects/textEditor/_deps/ftxui-src/include"
  INTERFACE_LINK_LIBRARIES "ftxui::screen"
)

# Create imported target ftxui::component
add_library(ftxui::component STATIC IMPORTED)

set_target_properties(ftxui::component PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "/home/hnakamura/vsc_projects/textEditor/_deps/ftxui-src/include"
  INTERFACE_LINK_LIBRARIES "ftxui::dom;Threads::Threads"
)

# Import target "ftxui::screen" for configuration "Debug"
set_property(TARGET ftxui::screen APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ftxui::screen PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/hnakamura/vsc_projects/textEditor/_deps/ftxui-build/libftxui-screen.a"
  )

# Import target "ftxui::dom" for configuration "Debug"
set_property(TARGET ftxui::dom APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ftxui::dom PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/hnakamura/vsc_projects/textEditor/_deps/ftxui-build/libftxui-dom.a"
  )

# Import target "ftxui::component" for configuration "Debug"
set_property(TARGET ftxui::component APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ftxui::component PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/hnakamura/vsc_projects/textEditor/_deps/ftxui-build/libftxui-component.a"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
