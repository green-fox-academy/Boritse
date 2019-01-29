//
// Created by Borbáls on 2019. 01. 29..
//

#include "animals.h"


animals::animals(){
    hunger=50;
    thirst=50;
}

void animals::eat(){
    hunger-=1;
}

void animals::drink(){
    thirst-=1;
}

void animals::play(){
    hunger+=1;
    thirst+=1;
}

int animals::getHunger() {
    return hunger;
}

int animals::getThirst(){
    return thirst;
}