//
// Created by Guoping Huang on 8/8/16.
//

#ifndef LASERDOCKLIB_JAVAUSBDEVICEHELPER_H
#define LASERDOCKLIB_JAVAUSBDEVICEHELPER_H

#include <memory>

#include <jni.h>

class JavaUsbDeviceHelper {

public:
    static JavaUsbDeviceHelper *getInstance();

    jobjectArray getLaserdockDevices();
    jint openDevice(jobject usbDevice);

private:
    explicit JavaUsbDeviceHelper();
    virtual ~JavaUsbDeviceHelper();
};

#endif //LASERDOCKLIB_JAVAUSBDEVICEHELPER_H
