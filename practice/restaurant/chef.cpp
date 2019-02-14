//
// Created by Borbáls on 2019. 02. 13..
//

#include "chef.h"
#include <iostream>

Chef::Chef() : Employee(){
    _type="chef";
}
Chef::Chef(int experience) : Employee(experience){}

void Chef::work(){
    _experience++;
    _type="chef";
}

void Chef::cook(std::string meal){
    bool cookedBefore=false;
    for(int i=0; i<_meals.size(); i++){
        if(_meals[i].first==meal){
            _meals[i].second++;
            cookedBefore=true;
        }
    }
    if(!cookedBefore){
        _meals.push_back(make_pair(meal, 1));
    }
}

void Chef::getMeals(){
    for(int i=0; i<_meals.size(); i++){
        std::cout << _meals[i].first << " cooked " << _meals[i].second << " times" << std::endl;
    }
}