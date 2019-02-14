//
// Created by Borbáls on 2019. 02. 05..
//

#include "sponsor.h"
#include "person.h"
#include <iostream>
#include <string>

Sponsor::Sponsor(){
    name="Jane Doe";
    age=30;
    gender=FEMALE;
    company="Google";
    hiredStudents=0;
}
Sponsor::Sponsor(std::string _name, int _age, Gender _gender, std::string _company){
    hiredStudents=0;
    name=_name;
    age=_age;
    gender=_gender;
    company=_company;
}
void Sponsor::getGoal(){
    std::cout << goalIs+goal << std::endl;
}
void Sponsor::hire(){
    hiredStudents++;
}
void Sponsor::introduce(){
    std::cout << "Hi, I'm "+name+", a "+std::to_string(age)+" year old "+::getGender(gender)+", who represents "+company+" and hired "+std::to_string(hiredStudents)+" students so far." << std::endl;
}