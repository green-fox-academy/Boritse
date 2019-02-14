//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include "Employee.h"

class Manager : public Employee{
public:
    Manager();
    Manager(int experience);
    void work() override;
    void haveaMeeting();
private:
    int _moodLevel;
};


#endif //RESTAURANT_MANAGER_H
