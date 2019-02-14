//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef GREENFOX_STUDENT_H
#define GREENFOX_STUDENT_H

#include <string>
#include "person.h"

class Student : public Person{
public:
    Student();
    Student(std::string _name, int _age, Gender _gender, std::string _prevorg);
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);
private:
    std::string previousOrganization;
    int skippedDays=0;
    std::string goal="Be a junior software developer.";
};


#endif //GREENFOX_STUDENT_H
