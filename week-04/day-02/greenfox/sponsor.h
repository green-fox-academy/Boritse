//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef GREENFOX_SPONSOR_H
#define GREENFOX_SPONSOR_H
#include <string>
#include "person.h"

class Sponsor : public Person{
public:
    Sponsor();
    Sponsor(std::string _name, int _age, Gender _gender, std::string _company);
    void getGoal() override;
    void hire();
    void introduce() override;
private:
    std::string company;
    int hiredStudents;
    std::string goal="Hire brilliant junior software developers.";
};


#endif //GREENFOX_SPONSOR_H
