//
// Created by Borbáls on 2019. 01. 30..
//

#include "Animal.h"
#include "Farm.h"


Animal::Animal(){
    hunger=50;
    thirst=50;
}

void Animal::eat(){
    hunger-=1;
}

void Animal::drink(){
    thirst-=1;
}

void Animal::play(){
    hunger+=1;
    thirst+=1;
}

int Animal::getHunger() {
    return hunger;
}

int Animal::getThirst(){
    return thirst;
}