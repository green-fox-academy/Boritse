//
// Created by Borbáls on 2019. 01. 30..
//

#include "station.h"
#include "car.h"
#include <string>
#include <iostream>

station::station(int _gasAmount) {
    gasAmount=_gasAmount;
}

int station::currentGasAmount(){
    return gasAmount;
}

void station::fill(car c){
    while(!c.isFull()){
        c.fill();
        gasAmount--;
        std::cout << station::currentGasAmount() << " ";
        std::cout << "Filling car!" << std::endl;
    }
}