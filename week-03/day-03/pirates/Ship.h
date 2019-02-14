//
// Created by Borbáls on 2019. 02. 02..
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <vector>
#include "Pirates.h"

class Ship {
public:
    Ship();
    void fillShip(Pirates& _captain);
    int captainRumLevel(Pirates _captain);
    int aliveCrew();
    bool battle(Ship _othership);
private:
    std::vector<Pirates> piratesShip;
};


#endif //PIRATES_SHIP_H
