//
// Created by Borbáls on 2019. 02. 05..
//
#include <string>
#include "aircrafts.h"

std::string getType(AircraftType _type){
    if(_type==AircraftType::F16){
        return "F16";
    }else{
        return "F35";
    }
}

Aircrafts::Aircrafts(AircraftType _type){
    if(_type==F16){
        currentAmmo=0;
        maxAmmo=8;
        baseDamage=30;
        allDamage=0;
        type=F16;
        priority=false;
    }else{
        currentAmmo=0;
        maxAmmo=12;
        baseDamage=50;
        allDamage=0;
        type=F35;
        priority=true;
    }
}

int Aircrafts::getNeededAmmo(){
    return maxAmmo-currentAmmo;
}

int Aircrafts::fight(){
    allDamage=baseDamage*currentAmmo;
    currentAmmo=0;
    return allDamage;
}
int Aircrafts::refill(int fill){
    int amountNeeded=maxAmmo-currentAmmo;
    if(amountNeeded<=fill) {
        currentAmmo += amountNeeded;
        return fill - amountNeeded;
    }else{
        currentAmmo+=fill;
        return 0;
    }
}

std::string Aircrafts::getStatus(){
        return "Type: "+::getType(type)+", Ammo: "+std::to_string(currentAmmo)+", Base Damage: "+std::to_string(baseDamage)+", All Damage: "+std::to_string(allDamage);
}
bool Aircrafts::isPriority(){
    return priority;
}