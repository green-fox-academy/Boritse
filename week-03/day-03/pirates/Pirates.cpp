//
// Created by Borbáls on 2019. 02. 02..
//
#include <iostream>
#include "Pirates.h"

Pirates::Pirates(){
    int levelOfRum=0;
    int timesOfDrinking=0;
    bool alive;
}

void Pirates::drinkSomeRum()
{
    if(alive) {
        levelOfRum += 5;
        timesOfDrinking++;
    }else{
        deadMessage();
    }
}

int Pirates::getTimesOfDrinking() {
    return timesOfDrinking;
}

void Pirates::howsItGoingMate()
{
    if(alive) {
        if (timesOfDrinking >= 0 && timesOfDrinking <= 4) {
            std::cout << "Pour me anudder!" << std::endl;
            drinkSomeRum();
        } else {
            std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
        }
    }else{
        deadMessage();
    }
}

int Pirates::getlevelOfRum() {
    if(alive) {
        return levelOfRum;
    }else{
        deadMessage();
    }
}

bool Pirates::die() {
    return !alive;
}

void Pirates::deadMessage(){
    std::cout << "Pirate is dead." << std::endl;
}

// for(int i=0; i<((rand()%4)+1); i++){