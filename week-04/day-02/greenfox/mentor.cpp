//
// Created by Borbáls on 2019. 02. 05..
//
#include <iostream>
#include <string>
#include "mentor.h"
#include "person.h"

std::string getLevel(Level _level){
    if(_level==JUNIOR){
        return "junior";
    }else if(_level==INTERMEDIATE){
        return "intermediate";
    }else{
        return "senior";
    }
}

Mentor::Mentor(){
    name="Jane Doe";
    age=30;
    gender=FEMALE;
    level=INTERMEDIATE;
}
Mentor::Mentor(std::string _name, int _age, Gender _gender, Level _level){
    name=_name;
    age=_age;
    gender=_gender;
    level=_level;
}
void Mentor::getGoal(){
    std::cout << goalIs+goal << std::endl;
}
void Mentor::introduce(){
    std::cout << "Hi, I'm "+name+", a "+std::to_string(age)+" year old "+::getGender(gender)+", "+getLevel(level)+" mentor." << std::endl;
}