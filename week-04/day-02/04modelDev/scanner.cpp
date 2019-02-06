//
// Created by Borbáls on 2019. 02. 06..
//
#include <iostream>
#include "scanner.h"

Scanner::Scanner(int speed){
    _speed=speed;
}
std::string Scanner::scan(){
    std::string message= "I'm scanning a document "+std::to_string(_speed)+" ppm";
    return message;
}