//
// Created by Borbáls on 2019. 02. 06..
//
#include <iostream>
#include "electricGuitar.h"

ElectricGuitar::ElectricGuitar(int _numberOfStrings, std::string _uniqueSound) : StringedInstrument(name, numberOfStrings, uniqueSound) {
    uniqueSound=_uniqueSound;
    numberOfStrings=_numberOfStrings;
}

void ElectricGuitar::sound(){
    std::cout << uniqueSound << std::endl;
}