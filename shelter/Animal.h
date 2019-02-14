//
// Created by Borbáls on 2019. 02. 09..
//

#ifndef SHELTER_ANIMAL_H
#define SHELTER_ANIMAL_H

#include <string>

class Animal {
public:
    Animal();
    Animal(std::string);
    void heal();
    int getHealCost();
    bool isAdoptable();
    std::string toString();

protected:
    std::string _name;
    bool _isHealthy;
    int _healCost;
};


#endif //SHELTER_ANIMAL_H

