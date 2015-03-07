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
set(CMAKE_BUILD_TYPE Debug)

# Flags
if(NOT WIN32)
  set(CMAKE_C_FLAGS "-Wall -pedantic -Wimplicit-function-declaration -Wreturn-type -Wstrict-prototypes -Wextra -fPIC")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

# Collect source files
file(GLOB_RECURSE SOURCES src/*.c*)

# libary headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Build library
add_library(${LIB} ${SOURCES})
target_link_libraries(${LIB})

# Generate cgo wrapper
add_custom_command(TARGET gb
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -P ${PROJECT_SOURCE_DIR}/BindConfig.txt ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include $<TARGET_FILE:gb>
)
