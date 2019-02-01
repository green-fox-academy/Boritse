//
// Created by Borbáls on 2019. 01. 30..
//

#include "sharpie.h"

sharpie::sharpie(std::string _colour, float _width){
    inkAmount=11;
}

float sharpie::use() {
    inkAmount-=3;
    return inkAmount;
}

int sharpie::currentInk() {
    return inkAmount;
}