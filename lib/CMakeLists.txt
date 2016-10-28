set(LASERDOCKLIB_SOURCE_FILES
        LaserdockDevice.cpp
        LaserdockDevice.h
        LaserdockDeviceManager.cpp
        LaserdockDeviceManager.h
        )

add_library(laserdocklib SHARED ${LASERDOCKLIB_SOURCE_FILES})


if(WIN32)
    file(GLOB_RECURSE LIBUSB
        ${CMAKE_CURRENT_SOURCE_DIR}/libusb/*.lib
    )
endif()

if(APPLE)
    file(GLOB_RECURSE LIBUSB
        ${CMAKE_CURRENT_SOURCE_DIR}/libusb/*.dylib
    )
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX)
    file(GLOB_RECURSE LIBUSB
        ${CMAKE_CURRENT_SOURCE_DIR}/libusb/*.so
    )
endif()




target_link_libraries(laserdocklib ${LIBUSB})
