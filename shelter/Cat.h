//
// Created by Borbáls on 2019. 02. 09..
//

#ifndef SHELTER_CAT_H
#define SHELTER_CAT_H

#include <ctime>
#include "Animal.h"

class Cat : public Animal{
public:
    Cat();
    Cat(std::string name);
protected:
    int _healCost=rand()%7;
};


#endif //SHELTER_CAT_H


// We are working with 3 types of Animals
// -  Cat's healing cost should be a random number between 0 and 6
// -  Dog's healing cost should be a random number between 1 and 8
// -  Parrot's healing cost should be a random number between 4 and 10