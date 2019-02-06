//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_02WIRELESS_NETWORKDEVICE_H
#define INC_02WIRELESS_NETWORKDEVICE_H

#include "device.h"

class Networkdevice : virtual public Device {
public:
    Networkdevice(int id, int bandwidth);
protected:
    int _bandwidth;
};


#endif //INC_02WIRELESS_NETWORKDEVICE_H
