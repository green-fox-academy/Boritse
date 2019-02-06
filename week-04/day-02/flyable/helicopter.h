//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "flyable.h"
#include "vehicle.h"

class Helicopter : public Vehicle, public Flyable{
public:
    Helicopter();
    void move() override;
    void fly() override;
    void takeoff() override;
    void land() override;
};


#endif //FLYABLE_HELICOPTER_H
