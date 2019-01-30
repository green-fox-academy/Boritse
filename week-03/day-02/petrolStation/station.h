//
// Created by Borbáls on 2019. 01. 30..
//

#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H

#include "car.h"

class station {
public:
    station(int _gasAmount);
    int currentGasAmount();
    void fill(car);
private:
    int gasAmount;
};


#endif //PETROLSTATION_STATION_H
