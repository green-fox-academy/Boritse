//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef AIRCRAFT_CARRIER_H
#define AIRCRAFT_CARRIER_H

#include "aircraft.h"
#include <vector>

class Carrier {
public:
    Carrier(int ammoInput, int healthPoint);
    void add(Aircraft* aircraft);
    void fill();
    int getAmmoStored();
    void fight(Carrier &carrier);
    int getHP();
private:
    std::vector<Aircraft*> _aircrafts;
    int _ammoStored;
    int _healthPoint;
};


#endif //AIRCRAFT_CARRIER_H
