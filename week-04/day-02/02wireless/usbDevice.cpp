//
// Created by Borbáls on 2019. 02. 06..
//

#include "usbDevice.h"

UsbDevice::UsbDevice(int id, int usbType) : Device(_id) {
    _usbType=usbType;
}