# Copyright 2012 Douglas Linder
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required (VERSION 2.8)
project (GB)
set(LIB "gb")

# Debug mode?
set(CMAKE_BUILD_TYPE Release)

# Flags
set(CMAKE_C_FLAGS "-Wall -pedantic -Wimplicit-function-declaration -Wreturn-type -Wstrict-prototypes -Wextra -fPIC")
if(NOT WIN32)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
endif()

# Code type
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# Collect source files
file(GLOB_RECURSE SOURCES src/*.c*)

# libary headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/python/include/python2.7)

# Python dep
set(PYTHON_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/python)
set(PYTHON_LIB ${PYTHON_INSTALL}/lib/libpython2.7.a)
include(ExternalProject)
ExternalProject_Add(
  python_external
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/python
  INSTALL_DIR ${PYTHON_INSTALL}
  CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/deps/python/configure --prefix=${PYTHON_INSTALL}
  BUILD_COMMAND ${MAKE}
)
add_library(python UNKNOWN IMPORTED)
set_property(TARGET python PROPERTY IMPORTED_LOCATION ${PYTHON_LIB})
add_dependencies(python python_external)

# Build library
add_library(${LIB} ${SOURCES})
target_link_libraries(${LIB} python)

# Build sample executable
add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/bin/demo.c)
targeT_link_libraries(demo ${LIB} python)

# Generate cgo wrapper
get_property(LIBRARY_PATH TARGET ${LIB} PROPERTY LOCATION)
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBRARIES "${LIBRARY_PATH} ${PYTHON_LIB}")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/demo/src/bridge/bridge.go.in ${CMAKE_CURRENT_SOURCE_DIR}/demo/src/bridge/bridge.go)
