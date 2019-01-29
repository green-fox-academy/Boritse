//
// Created by Borbáls on 2019. 01. 29..
//

#include "sharpie.h"

sharpie::sharpie(std::string colour, float width){
    inkAmount=100;
}

float sharpie::use() {
    inkAmount-=3;
    return inkAmount;
}