//
// Created by Borbáls on 2019. 02. 13..
//

#ifndef RESTAURANT_RESTAURANT_H
#define RESTAURANT_RESTAURANT_H

#include <string>
#include <vector>
#include "Employee.h"

class Restaurant
{
 public:
  Restaurant(std::string name, int foundedIn);
  void guestsArrived();
  void hire(Employee &employee);
  void getExperience();
  void getMenu();
  bool isChef(Employee*);
 private:
  std::string _name;
  int _foundedIn;
  std::vector<Employee *> _employees;
};

#endif //RESTAURANT_RESTAURANT_H

