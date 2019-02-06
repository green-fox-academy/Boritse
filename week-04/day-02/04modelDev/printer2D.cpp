//
// Created by Borbáls on 2019. 02. 06..
//

#include "printer2D.h"
#include <string>

Printer2D::Printer2D(int sizeX, int sizeY) {
    _sizeX=sizeX;
    _sizeY=sizeY;
}
std::string Printer2D::getSize(){
    return std::to_string(_sizeX)+" + "+std::to_string(_sizeY);
}