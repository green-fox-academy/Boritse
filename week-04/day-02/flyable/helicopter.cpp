//
// Created by Borbáls on 2019. 02. 06..
//

#include "helicopter.h"
#include <iostream>

Helicopter::Helicopter() : Vehicle(), Flyable() {
    weight=1000;
    speed=150;
    amountOfPeopleCarried=4;
}
void Helicopter::move(){
    std::cout << "Im on the move, baby!" << std::endl;
}
void Helicopter::fly(){
    std::cout << "Im flying, maaan!" << std::endl;
}
void Helicopter::takeoff(){
    std::cout << "Trying to take off, please dont disturb!" << std::endl;
}
void Helicopter::land(){
    std::cout << "Trying to land, hang there!" << std::endl;
}