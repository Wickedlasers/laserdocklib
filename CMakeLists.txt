cmake_minimum_required(VERSION 3.5)
project(laserdocklib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9")
endif()

add_subdirectory(lib)
add_subdirectory(tests)

message(STATUS "LIBRARIES = ${LIBRARIES}")
