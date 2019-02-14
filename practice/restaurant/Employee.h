//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef RESTAURANT_EMPLOYEE_H
#define RESTAURANT_EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee();
    Employee(int experience);
    virtual void work()=0;
    int getExperience();
    std::string getType();
protected:
    std::string _name;
    int _experience;
    std::string _type;
};


#endif //RESTAURANT_EMPLOYEE_H
