cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set the project name and version
project(udp-recv VERSION 1.0)

# specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCES src/udp_recv.cc src/utils.cc)

# add the executable
add_executable(udp_recv ${SOURCES})

target_include_directories(udp_recv PUBLIC inc/)
