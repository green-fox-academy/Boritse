//
// Created by Borbáls on 2019. 02. 05..
//
#include <iostream>
#include "Carrier.h"
#include "aircrafts.h"

Carrier::Carrier(int _ammoStore, int _healthPoint){
    ammoStore=_ammoStore;
    healthPoint=_healthPoint;
};

void Carrier::add(Aircrafts &_aircraft) {
    _carrier.push_back(_aircraft);
}

void Carrier::fill() {
    int ammoNeeded = 0;
    for (int i = 0; i < _carrier.size(); i++) {
        ammoNeeded += _carrier[i].getNeededAmmo();
    }
    try {
        if (ammoStore <= 0) {
            throw 1;
        }else if(ammoNeeded>ammoStore){
            for(int i=0; i<_carrier.size(); i++){
                if(_carrier[i].isPriority()){
                    _carrier[i].refill(ammoStore);
                    if (ammoStore <= 0) {
                        throw 1;
                    }else {
                        ammoStore -= _carrier[i].getNeededAmmo();
                        ammoNeeded -= _carrier[i].getNeededAmmo();
                    }
                }
            }for(int i=0; i<_carrier.size(); i++){
                _carrier[i].refill(ammoStore);
                if (ammoStore <= 0) {
                    throw 1;
                }else {
                    ammoStore -= _carrier[i].getNeededAmmo();
                    ammoNeeded -= _carrier[i].getNeededAmmo();
                }
            }
    }
    }catch (int e) {
        std::cout << "No available ammo." << std::endl;
    }
}

void Carrier::fight(Carrier _otherCarrier){
    int allDamage=0;
    for(int i=0; i<_carrier.size(); i++)
        allDamage+=_carrier[i].fight();
    ammoStore-=allDamage;
}