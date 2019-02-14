//
// Created by Borbáls on 2019. 02. 05..
//
#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "mentor.h"
#include "cohort.h"

Cohort::Cohort(std::string _cohName){
    cohortName=_cohName;
}
void Cohort::addStudent(Student* _student){
    students.push_back(_student);
}
void Cohort::addMentor(Mentor* _mentor){
    mentors.push_back(_mentor);
}
void Cohort::info(){
    std::cout << "The "+cohortName+" cohort has "+std::to_string(students.size())+" students and "+std::to_string(mentors.size())+" mentors." << std::endl;
}

