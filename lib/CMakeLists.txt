cmake_minimum_required(VERSION 3.11)

project(laserdocklib)

add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src)

set(SRCDIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(INCDIR ${CMAKE_CURRENT_LIST_DIR}/include/laserdocklib)

target_sources(${PROJECT_NAME} PRIVATE
    ${INCDIR}/LaserdockDevice.h
    ${INCDIR}/LaserdockDeviceManager.h
    ${INCDIR}/Laserdocklib.h
    ${INCDIR}/LaserdockSample.h
    ${SRCDIR}/LaserdockDevice.cpp
    ${SRCDIR}/LaserdockDevice_p.h
    ${SRCDIR}/LaserdockDeviceManager.cpp
    ${SRCDIR}/LaserdockDeviceManager_p.h
    )

if(ANDROID)
    target_sources(${PROJECT_NAME} PRIVATE
        ${SRCDIR}/JavaUsbDeviceHelper.cpp
        ${SRCDIR}/JavaUsbDeviceHelper.h
        ${SRCDIR}/LaserdockDeviceManager_android.cpp
        ${SRCDIR}/LaserdockDevice_android.cpp
        java/com/wickedlasers/laserdocklib/UsbDeviceHelper.java
        )
else()
    target_sources(${PROJECT_NAME} PRIVATE
        ${SRCDIR}/LaserdockDeviceManager_desktop.cpp
        ${SRCDIR}/LaserdockDevice_desktop.cpp
        )
endif()

# libusb
add_subdirectory(3rdparty/libusb)
target_link_libraries(${PROJECT_NAME} PRIVATE libusb)


# Qt
if(ANDROID)
    find_package(Qt5 5.7.0 CONFIG REQUIRED Core AndroidExtras)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::AndroidExtras)
endif()

# install
if(NOT WIN32)
    include(GNUInstallDirs)
    set_property(TARGET laserdocklib PROPERTY PUBLIC_HEADER
        ${INCDIR}/Laserdocklib.h
        ${INCDIR}/LaserdockDevice.h
        ${INCDIR}/LaserdockDeviceManager.h
        ${INCDIR}/LaserdockSample.h
        )

    install(TARGETS laserdocklib
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/laserdocklib)
endif()
