//
// Created by Borbáls on 2019. 02. 02..
//

#include "Ship.h"
#include "Pirates.h"
#include <vector>
#include <iostream>

Ship::Ship(){
    std::vector<Pirates> piratesShip;
}

void Ship::fillShip(Pirates& _captain) {
    piratesShip.push_back(_captain);
    for(int i=0; i<((rand()%25)+1); i++){
        Pirates _pirate;
        piratesShip.push_back(_pirate);
    }
}

int Ship::captainRumLevel(Pirates _captain) {
    return _captain.getlevelOfRum();
}

int Ship::aliveCrew() {
    int aliveCounter=0;
    for(int i=0; i<piratesShip.size(); i++){
        if(!piratesShip[i].die()){
            aliveCounter++;
        }
    }
    return aliveCounter;
}

bool Ship::battle(Ship othership) {
    int shipScore=0;
    int otherShipScore=0;
    shipScore+=(aliveCrew()-piratesShip[0].getTimesOfDrinking());
    otherShipScore+=(aliveCrew()-othership.piratesShip[0].getTimesOfDrinking());
    if(shipScore>otherShipScore){
        for(int i=0; i<piratesShip.size(); i++) {
            for (int i = 0; i < ((rand() % 10) + 1); i++) {
                piratesShip[i].drinkSomeRum();
            }
        }
        for(int i=0; i<othership.piratesShip.size(); i++){
            for (int i = 0; i < ((rand() % 10) + 1); i++) {
                othership.piratesShip[i].die();
            }
        }
    }
    if(!shipScore>otherShipScore){
        for(int i=0; i<piratesShip.size(); i++) {
            for (int i = 0; i < ((rand() % 10) + 1); i++) {
                piratesShip[i].die();
            }
        }
        for(int i=0; i<othership.piratesShip.size(); i++){
            for (int i = 0; i < ((rand() % 10) + 1); i++) {
                othership.piratesShip[i].drinkSomeRum();
            }
        }
    }
    return shipScore>otherShipScore;
}