# --------------- Copyright (c) Takeoff Technical LLC 2022 -------------------
# Purpose: This is a demo C++ application using SDL2. It can be cross-compiled
#          using the toolchain file included with this repository.
# Refer:   https://takeofftechnical.com/x-compile-cpp-bbb
# License: MIT
# ----------------------------------------------------------------------------

# This is the CMake version at the time the application was first built
cmake_minimum_required(VERSION 3.13)

# Create the project for the hello world application
project(hello-x-compile VERSION 1.0)

# The C++ 2017 standard is the newest supported version by gcc at this time
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(hello-x-compile main.cpp)

# Add the Simple DirectMedia Layer (SDL) Dependency
find_package(SDL2 REQUIRED)
message(STATUS "SDL2 include paths: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2 libraries: ${SDL2_LIBRARIES}")

if(COMMAND prefix_sysroot_includes)
    prefix_sysroot_includes(SDL2_INCLUDE_DIRS)
    message(STATUS "Cross-compile SDL2 include paths: ${SDL2_INCLUDE_DIRS}")
endif()

target_include_directories(hello-x-compile PRIVATE "${SDL2_INCLUDE_DIRS}")
target_link_libraries(hello-x-compile PRIVATE "${SDL2_LIBRARIES}")
