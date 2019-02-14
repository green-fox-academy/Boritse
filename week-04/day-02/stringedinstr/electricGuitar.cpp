//
// Created by Borbáls on 2019. 02. 06..
//
#include <iostream>
#include "electricGuitar.h"

ElectricGuitar::ElectricGuitar(){
    numberOfStrings=6;
}

void ElectricGuitar::sound(){
    std::cout << soundInst << std::endl;
}
