//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_02WIRELESS_ADAPTER_H
#define INC_02WIRELESS_ADAPTER_H

#include "usbDevice.h"
#include "networkdevice.h"


class Adapter : public UsbDevice, public Networkdevice{
public:
    Adapter(int id, int usbType, int bandwidth);
    void info();
};


#endif //INC_02WIRELESS_ADAPTER_H
