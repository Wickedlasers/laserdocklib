cmake_minimum_required(VERSION 3.5)
project(laserdocklib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(local.cmake)

add_subdirectory(lib)
add_subdirectory(tests)

message(STATUS "LIBRARIES = ${LIBRARIES}")
