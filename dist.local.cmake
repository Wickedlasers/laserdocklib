# Uncomment this line to build Android version
# You should manually remove build dir and reopen CMake project from scratch after change this value
set(BUILD_ANDROID OFF)

# Print commands
set(CMAKE_VERBOSE_MAKEFILE ON)

# Setup Android environment
if(BUILD_ANDROID)
    include(local.android.cmake)
endif()