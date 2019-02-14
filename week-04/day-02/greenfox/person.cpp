//
// Created by Borbáls on 2019. 02. 05..
//
#include <iostream>
#include "person.h"

std::string getGender(Gender _gender){
    if(_gender==MALE){
        return "male";
    }else if(_gender==FEMALE){
        return "female";
    }else{
        return "other";
    }
}

Person::Person(){
    name="Jane Doe";
    age=30;
    gender=FEMALE;
}
Person::Person(std::string _name, int _age, Gender _gender){
    name=_name;
    age=_age;
    gender=_gender;
}

void Person::introduce(){
    std::cout << "Hi, I'm "+name+", a "+std::to_string(age)+" year old"+::getGender(gender)+"." << std::endl;
}
void Person::getGoal(){
    std::cout << goalIs+goal << std::endl;
}