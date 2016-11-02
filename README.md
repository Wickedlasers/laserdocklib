# laserdocklib
client library to connect to laserdock

This library has three targets

1. laserdocklib -> library target
2. laserdocktest -> simple test and printing of key parameters of laserdock
3. laserdockcircle -> shows a white circle, demonstrating sending data into laserdock

Tested under OS X 10.11 and comes with libusb 1.0 dylib.




How to build for Android:
Checked in Qt Creator with Qt 5.7 armeabi-v7a.
CMake configuration:
CMAKE_TOOLCHAIN_FILE=/Users/ncuxer/Projects/laserdocklib/platforms/android.cmake
CMAKE_CXX_COMPILER=/Users/ncuxer/Dev/android/sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-g++

Environment variables:
ANDROID_NDK=/Users/ncuxer/Dev/android/sdk/ndk-bundle
ANDROID_SDK=/Users/ncuxer/Dev/android/sdk