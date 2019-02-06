//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H

#include "flyable.h"
#include "animals.h"

class Bird : public Flyable, public Animals{
public:
    Bird();
    void fly() override;
    void takeoff() override;
    void land() override;
};


#endif //FLYABLE_BIRD_H
