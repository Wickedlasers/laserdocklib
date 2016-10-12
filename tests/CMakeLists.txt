include_directories(..)

set(LASERDOCKLIB_TEST_SOURCE_FILES main.cpp)
add_executable(laserdocklibtest ${LASERDOCKLIB_TEST_SOURCE_FILES})
target_link_libraries(laserdocklibtest laserdocklib ${LIBRARIES})

set(LASERDOCKLIB_CIRCLE_SOURCE_FILES laserdocklibcircle.cpp)
add_executable(laserdocklibcircle ${LASERDOCKLIB_CIRCLE_SOURCE_FILES})
target_link_libraries(laserdocklibcircle laserdocklib ${LIBRARIES})

set(LASERDOCKLIB_DEVICEMANAGERTEST_SOURCE_FILES laserdockdevicemanagertest.cpp)
add_executable(LaserdockDeviceManagerTest ${LASERDOCKLIB_DEVICEMANAGERTEST_SOURCE_FILES})
target_link_libraries(LaserdockDeviceManagerTest laserdocklib ${LIBRARIES})

set(LASERDOCKLIB_RUNNER_SOURCE_FILES runnertest.cpp)
add_executable(LaserdockRunnerTest ${LASERDOCKLIB_RUNNER_SOURCE_FILES})
target_link_libraries(LaserdockRunnerTest laserdocklib ${LIBRARIES})