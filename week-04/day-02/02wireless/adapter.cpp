//
// Created by Borbáls on 2019. 02. 06..
//

#include "adapter.h"
#include <iostream>

Adapter::Adapter(int id, int usbType, int bandwidth) : Networkdevice(id, usbType), UsbDevice(id, usbType), Device(id){
    _bandwidth=bandwidth;
    _usbType=usbType;
    _id=id;
}
void Adapter::info(){
    std::cout << "the adapter has an id: " << _id << ", a usbtype: " << _usbType << ", and a bandwidth: " << _bandwidth;
}
