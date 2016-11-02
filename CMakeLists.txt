cmake_minimum_required(VERSION 3.5)
project(laserdocklib)

#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9")
endif()

add_subdirectory(lib)
add_subdirectory(tests)

if (ANDROID)
    include(qt-android-cmake/AddQtAndroidApk.cmake)
    add_qt_android_apk(laserdocklibcircle_apk laserdocklibcircle
        JAVA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/lib/java
        PACKAGE_NAME "com.wickedlasers.laserdocklibcircle"
        DEPENDS laserdocklib
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lib/libusb/android-${ANDROID_ARCH_NAME}/libusb1.0.so
        INSTALL
        )

endif()
