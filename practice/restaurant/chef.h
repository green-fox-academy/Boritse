//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef RESTAURANT_CHEF_H
#define RESTAURANT_CHEF_H

#include "Employee.h"
#include <vector>

class Chef : public Employee {
public:
    Chef();
    Chef(int experience);
    void work() override;
    void cook(std::string meal);
    void getMeals();
private:
    std::vector<std::pair<std::string, int>> _meals;
};


#endif //RESTAURANT_CHEF_H
