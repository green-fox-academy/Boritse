//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef GREENFOX_MENTOR_H
#define GREENFOX_MENTOR_H

#include "person.h"

enum Level{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};
std::string getLevel(Level _level);

class Mentor : public Person {
public:
    Mentor();
    Mentor(std::string _name, int _age, Gender gender, Level _level);
    void getGoal() override;
    void introduce() override;
private:
    Level level;
    std::string goal="Educate brilliant junior software developers.";
};


#endif //GREENFOX_MENTOR_H
