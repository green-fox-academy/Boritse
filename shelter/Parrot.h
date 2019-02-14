//
// Created by Borbáls on 2019. 02. 09..
//

#ifndef SHELTER_PARROT_H
#define SHELTER_PARROT_H

#include <ctime>
#include "Animal.h"

class Parrot : public Animal{
public:
    Parrot();
    Parrot(std::string name);
protected:
    int _healCost=4+(rand()%7);
};

#endif //SHELTER_PARROT_H
