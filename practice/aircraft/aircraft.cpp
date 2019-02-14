//
// Created by Borbáls on 2019. 02. 13..
//

#include "aircraft.h"

Aircraft::Aircraft() {
    _type="aircraft";
}
int Aircraft::fight(){
    _currentDamage=_baseDamage*_currentAmmo;
    _currentAmmo=0;
    return _currentDamage;
}
std::string Aircraft::getType(){
    return _type;
}
std::string Aircraft::getStatus(){
    std::string status="Type: "+_type+", Ammo: "+std::to_string(_currentAmmo)+", Base Damage: "+std::to_string(_baseDamage)+", All Damage: "+std::to_string(_currentDamage);
    return status;
}
bool Aircraft::isPriority() {
    if (_type == "F16") {
        return false;
    }else{
        return true;
    }
}

int Aircraft::refill(int inputAmmo){
    if(inputAmmo>=getNeededAmmo()){
        _currentAmmo=_maxAmmo;
        inputAmmo-=getNeededAmmo();
        return inputAmmo;
    }else{
        _currentAmmo+=inputAmmo;
        inputAmmo=0;
        return inputAmmo;
    }
}

int Aircraft::getNeededAmmo() {
    return _maxAmmo-_currentAmmo;
}