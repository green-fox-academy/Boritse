//
// Created by Borbáls on 2019. 02. 07..
//

#include "sum.h"
#include <vector>

Sum::Sum(){}

void Sum::addInt(int _x) {
    integersToSum.push_back(_x);
}

int Sum::sum(std::vector<int> integersToSum){
    int summa=0;
    for(int i=0; i<integersToSum.size(); i++){
        summa+=integersToSum[i];
    }
    return summa;
}