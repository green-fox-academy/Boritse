//
// Created by Borbáls on 2019. 01. 29..
//

#include "counter.h"

counter::counter() {
    int count = 0;
}

void counter::add(){
    count+=1;
}

void counter::ADD(int x){
    count+=x;
}

int counter::get(){
    return count;
}

void counter::reset(){
    count=0;
}
