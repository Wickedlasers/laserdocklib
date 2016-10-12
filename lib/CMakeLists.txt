set(LASERDOCKLIB_SOURCE_FILES
        LaserdockDevice.cpp
        LaserdockDevice.h
        LaserdockDeviceManager.cpp
        LaserdockDeviceManager.h
        )

add_library(laserdocklib ${LASERDOCKLIB_SOURCE_FILES})
target_link_libraries(laserdocklib )
