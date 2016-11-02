#include "JavaUsbDeviceHelper.h"

#include <QtAndroid>
#include <QAndroidJniObject>

const char* USB_DEVICE_HELPER_CLASS_NAME = "com/wickedlasers/laserdocklib/UsbDeviceHelper";

JavaUsbDeviceHelper *JavaUsbDeviceHelper::getInstance()
{
    static JavaUsbDeviceHelper instance;
    return &instance;
}

jobjectArray JavaUsbDeviceHelper::getLaserdockDevices()
{
    QAndroidJniObject usbDevicesJni = QAndroidJniObject::callStaticObjectMethod(USB_DEVICE_HELPER_CLASS_NAME,
                                                                                "getLaserdockDevices",
                                                                                "(Landroid/content/Context;)[Landroid/hardware/usb/UsbDevice;",
                                                                                QtAndroid::androidActivity().object());

    return usbDevicesJni.object<jobjectArray>();
}

jint JavaUsbDeviceHelper::openDevice(jobject usbDevice)
{
    return QAndroidJniObject::callStaticMethod<jint>(USB_DEVICE_HELPER_CLASS_NAME,
                                                         "openDevice",
                                                         "(Landroid/content/Context;Landroid/hardware/usb/UsbDevice;)I",
                                                         QtAndroid::androidActivity().object(),
                                                         usbDevice
                                                     );
}


JavaUsbDeviceHelper::JavaUsbDeviceHelper()
{
}

JavaUsbDeviceHelper::~JavaUsbDeviceHelper()
{
}
