//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef AIRCRAFT_AIRCRAFT_H
#define AIRCRAFT_AIRCRAFT_H

#include <string>

class Aircraft {
public:
    Aircraft();
    int fight();
    int refill(int inputAmmo);
    int getNeededAmmo();
    std::string getType();
    std::string getStatus();
    bool isPriority();
protected:
    int _maxAmmo;
    int _currentAmmo;
    int _baseDamage;
    int _currentDamage;
    std::string _type;
};


#endif //AIRCRAFT_AIRCRAFT_H
