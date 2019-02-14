//
// Created by Borbáls on 2019. 02. 09..
//

#include "Animal.h"

Animal::Animal(){
    _isHealthy=false;
}
int Animal::getHealCost(){
    return _healCost;
}
Animal::Animal(std::string name){
    _name=name;
    _isHealthy=false;
}

void Animal::heal(){
    _isHealthy=true;
}

bool Animal::isAdoptable() {
    if(_isHealthy){
        return true;
    }else{
        return false;
    }
}

std::string Animal::toString() {
    if(isAdoptable()){
        return _name+" is healthy and adoptable";
    }else{
        return _name+" is not healthy, the cost of healing is: "+std::to_string(_healCost)+", and is currently not adoptable";
    }
}
// An Animal
// -  has a `name` and stores it's health state in a boolean
// -  has a `healCost` field
// -  has a method named `heal()`, that sets the `isHealthy` field's status to true
// -  has a method named `isAdoptable()` that returns a boolean value whether it can be adopted or not (an animal can be adopted if it is healthy)
// -  has a method named `toString()` that represents the Animal in the following format:
// <name> is not healthy (<heal cost>€), and not adoptable
// <name> is healthy, and adoptable
// The animal's name is the same as the class name by default, but it can be set thought constructor as well