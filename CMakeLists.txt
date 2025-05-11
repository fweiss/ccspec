cmake_minimum_required(VERSION 3.28.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BIICODE)
  include("biicode.cmake")
  return()
endif()

if(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
endif()

project(ccspec)
add_subdirectory(src)
add_subdirectory(spec)
enable_testing()
add_test(NAME ccspec_spec COMMAND ccspec_spec)
