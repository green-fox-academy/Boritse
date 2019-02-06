//
// Created by Borbáls on 2019. 02. 06..
//

#include "animals.h"

Animals::Animals(){
    hunger=50;
    thirst=50;
}

void Animals::eat(){
    hunger-=1;
}

void Animals::drink(){
    thirst-=1;
}

void Animals::play(){
    hunger+=1;
    thirst+=1;
}

int Animals::getHunger() {
    return hunger;
}

int Animals::getThirst(){
    return thirst;
}
