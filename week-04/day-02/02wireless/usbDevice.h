//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_02WIRELESS_USBDEVICE_H
#define INC_02WIRELESS_USBDEVICE_H

#include "device.h"

class UsbDevice : public virtual Device {
public:
    UsbDevice(int id, int usbType);
protected:
    int _usbType;
};


#endif //INC_02WIRELESS_USBDEVICE_H
