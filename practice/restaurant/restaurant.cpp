//
// Created by Borbáls on 2019. 02. 13..
//

#include "restaurant.h"
#include <iostream>

Restaurant::Restaurant(std::string name, int foundedIn)
{
    _name = name;
    _foundedIn = foundedIn;
}

void Restaurant::guestsArrived()
{
    for (int i = 0; i < _employees.size(); i++) {
        _employees[i]->work();
    }
}

void Restaurant::hire(Employee &employee)
{
    _employees.push_back(&employee);
}

void Restaurant::getExperience()
{
    for (int i = 0; i < _employees.size(); i++) {
        std::cout << _employees[i]->getExperience() << std::endl;
    }
}

void Restaurant::getMenu()
{
    for (int i = 0; i < _employees.size(); i++) {
        if (_employees[i]->getType() == "chef"){
                _employees[i].getMeals()
        }
    }
}
