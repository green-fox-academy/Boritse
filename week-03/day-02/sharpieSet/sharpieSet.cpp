//
// Created by Borbáls on 2019. 01. 30..
//

#include "sharpieSet.h"
#include "sharpie.h"
#include <vector>
#include <algorithm>
#include <iterator>

sharpieSet::sharpieSet() {

}

void sharpieSet::fillMyVect()
{
    sharpvect.push_back(black);
    sharpvect.push_back(green);
    sharpvect.push_back(blue);
    sharpvect.push_back(pink);
    sharpvect.push_back(purple);
}

int sharpieSet::countUsuable()
{
    int x=0;
    for(int i=0; i<sharpvect.size(); i++){
        if(sharpvect[i].currentInk()!=0){
            x++;
        }
    }
    return x;
}

void sharpieSet::removeTrash() {
    for(int i=0; i<sharpvect.size(); i++){
        if(sharpvect[i].currentInk()<=0){
            sharpvect.erase(sharpvect.begin() +i);
        }
    }
}

void sharpieSet::useSharpie(int i) {
    sharpvect[i].use();
}