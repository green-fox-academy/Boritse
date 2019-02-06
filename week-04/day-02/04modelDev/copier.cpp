//
// Created by Borbáls on 2019. 02. 06..
//

#include "copier.h"

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed){
    _sizeX=sizeX;
    _sizeY=sizeY;
    _speed=speed;
}
std::string Copier::copy(){
    return scan()+" + "+print();
}
