//
// Created by Borbáls on 2019. 01. 30..
//
#ifndef FARM_FARM_H
#define FARM_FARM_H

#include <iostream>
#include <vector>
#include "Animal.h"

class Farm {
public:
    Farm();
    void breed();
    void slaughter();
    void currentNumberOfSlots();
    void feed(int i);
    void water(int i);
    void play(int i);
private:
    int slots=10;
    std::vector<Animal> animals;
};


#endif //FARM_FARM_H
