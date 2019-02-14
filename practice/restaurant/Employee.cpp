//
// Created by Borbáls on 2019. 02. 13..
//

#include "Employee.h"

Employee::Employee() {
    _experience=0;
}

Employee::Employee(int experience) {
    _experience=experience;
}

int Employee::getExperience(){
    return _experience;
}

std::string Employee::getType()
{
    return _type;
}