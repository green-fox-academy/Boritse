//
// Created by Borbáls on 2019. 02. 13..
//

#include "manager.h"

Manager::Manager() : Employee(){
    _moodLevel=400;
    _type="manager";
}

Manager::Manager(int experience) : Employee(experience){
    _moodLevel=400;
    _type="manager";
}

void Manager::work(){
    _experience++;
    haveaMeeting();
}

void Manager::haveaMeeting(){
    _moodLevel-=_experience;
}