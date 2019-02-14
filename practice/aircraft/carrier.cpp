//
// Created by Borbáls on 2019. 02. 13..
//

#include "carrier.h"
#include <iostream>

Carrier::Carrier(int ammoInput, int healthPoint) {
    _ammoStored=ammoInput;
    _healthPoint=healthPoint;
}

void Carrier::add(Aircraft* aircraft){
    _aircrafts.push_back(aircraft);
}

void Carrier::fill(){
    try {
        int neededAmmo = 0;
        if (_ammoStored == 0) {
            throw "exception";
        }
        for (int i = 0; i < _aircrafts.size(); i++) {
            neededAmmo += _aircrafts[i]->getNeededAmmo();
        }
        if (_ammoStored > 0 && _ammoStored < neededAmmo) {
            for (int i = 0; i < _aircrafts.size(); i++) {
                int currentNeededAmmo = _aircrafts[i]->getNeededAmmo();
                if ((_aircrafts[i]->isPriority()) && (_ammoStored >= currentNeededAmmo)) {
                    _aircrafts[i]->refill(_ammoStored);
                    _ammoStored -= currentNeededAmmo;
                } else if ((_aircrafts[i]->isPriority()) && (_ammoStored > 0) && _ammoStored < currentNeededAmmo) {
                    _aircrafts[i]->refill(_ammoStored);
                    _ammoStored = 0;
                }
            }
        } else {
            for (int i = 0; i < _aircrafts.size(); i++) {
                int currentNeededAmmo = _aircrafts[i]->getNeededAmmo();
                if (_ammoStored >= currentNeededAmmo) {
                    _aircrafts[i]->refill(_ammoStored);
                    _ammoStored -= currentNeededAmmo;
                } else if (_ammoStored < currentNeededAmmo && _ammoStored > 0) {
                    _aircrafts[i]->refill(_ammoStored);
                    _ammoStored = 0;
                }
            }
        }
    }catch (...){
        std::cout << "Sorry to say but your carrier ran out of ammo" << std::endl;
    }
}

int Carrier::getAmmoStored(){
    return _ammoStored;
}

void Carrier::fight(Carrier &carrier){
    int allDamage=0;
    for(int i=0; i<_aircrafts.size(); i++){
        allDamage+=_aircrafts[i]->fight();
    }
    carrier._healthPoint-=allDamage;
    if(carrier._healthPoint<=0){
        std::cout << "It's dead, Jim:(" << std::endl;
    }
}

int Carrier::getHP(){
    return _healthPoint;
}