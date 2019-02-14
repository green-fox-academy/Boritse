//
// Created by Borbáls on 2019. 02. 09..
//

#ifndef SHELTER_DOG_H
#define SHELTER_DOG_H

#include <ctime>
#include "Animal.h"

class Dog : public Animal{
public:
    Dog();
    Dog(std::string name);
protected:
    int _healCost=1+(rand()%8);
};


#endif //SHELTER_DOG_H
