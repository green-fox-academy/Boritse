//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef RESTAURANT_WAITER_H
#define RESTAURANT_WAITER_H


#include "Employee.h"

class Waiter : public Employee {
public:
    Waiter();
    Waiter(int experience);
    void work() override;
private:
    int _tip;
};


#endif //RESTAURANT_WAITER_H
