//
// Created by Borbáls on 2019. 02. 06..
//

#include "device.h"

Device::Device(int id) {
    _id=id;
}
int Device::getID(){
    return _id;
}