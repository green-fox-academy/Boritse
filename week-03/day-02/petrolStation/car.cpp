//
// Created by Borbáls on 2019. 01. 30..
//

#include "car.h"
#include "station.h"

car::car(int _gasAmount, int _capacity)
{
    gasAmount=_gasAmount;
    capacity=_capacity;
}

bool car::isFull()
{
    return capacity==gasAmount;
}

void car::fill()
{
    gasAmount++;
}

int car::getGasAmount(){
        return gasAmount;
}