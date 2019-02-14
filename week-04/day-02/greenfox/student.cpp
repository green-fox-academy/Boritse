//
// Created by Borbáls on 2019. 02. 05..
//
#include <iostream>
#include <string>
#include "student.h"
#include "person.h"

Student::Student(){
    name="Jane Doe";
    age=30;
    gender=FEMALE;
    previousOrganization="The School of Life";
}
Student::Student(std::string _name, int _age, Gender _gender, std::string _prevorg){
    name=_name;
    age=_age;
    gender=_gender;
    previousOrganization=_prevorg;
}

void Student::getGoal(){
    std::cout << goalIs+goal;
}
void Student::introduce(){
    std::cout << "Hi, I'm "+name+", a "+std::to_string(age)+" year old "+::getGender(gender)+" from "+previousOrganization+" who skipped "+std::to_string(skippedDays)+" days from the course already." << std::endl;
}
void Student::skipDays(int numberOfDays){
    skippedDays+=numberOfDays;
}