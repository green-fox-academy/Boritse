//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H

#include "aircrafts.h"
#include <vector>

class Carrier {
public:
    Carrier(int _ammoStore, int _healthPoint);
    void add(Aircrafts &_aircraft);
    void fill();
    void fight(Carrier _otherCarrier);
private:
    std::vector<Aircrafts> _carrier;
    int ammoStore;
    int healthPoint;
};


#endif //AIRCRAFTCARRIER_CARRIER_H
