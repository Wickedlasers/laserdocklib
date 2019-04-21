cmake_minimum_required(VERSION 3.5)
project(laserdocklib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(LIBUSB_SKIP_VERSION_CHECK TRUE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message(WARNING "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")

find_package(LibUSB REQUIRED)

# include(local.cmake)

set(LAERDOCKLIB_SOURCE_FILES LaserdockDevice.cpp LaserdockDevice.h LaserdockDeviceManager.cpp LaserdockDeviceManager.h hexDump.cpp )
set(LAERDOCKLIB_TEST_SOURCE_FILES main.cpp)
set(LAERDOCKLIB_CIRCLE_SOURCE_FILES laserdocklibcircle.cpp)
set(LAERDOCKLIB_DEVICEMANAGERTEST_SOURCE_FILES laserdockdevicemanagertest.cpp)
set(LaserdockRunnerTestSources runnertest.cpp hexDump.cpp )

add_library(laserdocklib ${LAERDOCKLIB_SOURCE_FILES})
add_executable(funcpointers funcpointers.cpp)
add_executable(laserdocklibtest ${LAERDOCKLIB_TEST_SOURCE_FILES})
# add_executable(laserdocklibcircle ${LAERDOCKLIB_CIRCLE_SOURCE_FILES})
# add_executable(LaserdockDeviceManagerTest ${LAERDOCKLIB_DEVICEMANAGERTEST_SOURCE_FILES})
# add_executable(LaserdockRunnerTest ${LaserdockRunnerTestSources})

target_link_libraries(laserdocklibtest laserdocklib ${LIBUSB_LIBRARIES})
# target_link_libraries(laserdocklibcircle laserdocklib ${LIBRARIES})
# target_link_libraries(LaserdockDeviceManagerTest laserdocklib ${LIBRARIES})
# target_link_libraries(LaserdockRunnerTest laserdocklib ${LIBRARIES})

message(WARNING "LIBRARIES = ${LIBRARIES}")
