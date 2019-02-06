//
// Created by Borbáls on 2019. 02. 06..
//
#include <iostream>
#include <string>
#include "printer.h"

Printer::Printer() {}

std::string Printer::print(){
    std::string message="I'm printing something that's "+getSize()+" cm.";
    return message;
}