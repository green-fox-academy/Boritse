//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef GREENFOX_PERSON_H
#define GREENFOX_PERSON_H

#include <string>

enum Gender{
    MALE,
    FEMALE,
    OTHER
};
std::string getGender(Gender _gender);

class Person {
public:
    Person();
    Person(std::string _name, int _age, Gender _gender);
    virtual void introduce();
    virtual void getGoal();
protected:
    int age;
    std::string name;
    Gender gender;
    std::string goalIs="My goal is: ";
private:
    std::string goal="Live for the moment!";
};


#endif //GREENFOX_PERSON_H
