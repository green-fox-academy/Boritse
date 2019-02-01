//
// Created by Borbáls on 2019. 01. 30..
//

#include "Farm.h"
#include "Animal.h"
#include <vector>
#include <iostream>

Farm::Farm(){}

void Farm::breed()
{
    if(slots!=0){
        Animal _animal;
        animals.push_back(_animal);
        slots--;
        currentNumberOfSlots();
    }else{
        std::cout << "No more space for animals, please slaughter or bye more land" << std::endl;
    }
}

void Farm::slaughter()
{
    int x=0;
    for(int i=0; i<animals.size(); i++){
        if(animals[i].getHunger() < animals[0].getHunger()){
            x=i;
        }
    }
    animals.erase(animals.begin() + x);
    slots++;
}

void Farm::currentNumberOfSlots() {
    std::cout << "Current number of remaining slots: " << slots << std::endl;
}

void Farm::feed(int i){
    animals[i].eat();
}

void Farm::water(int i){
    animals[i].drink();
}

void Farm::play(int i){
    animals[i];
}