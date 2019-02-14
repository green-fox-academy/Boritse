//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_03ZOO_ANIMAL_H
#define INC_03ZOO_ANIMAL_H

#include <string>

class Animal {
public:
    Animal(std::string name);
    virtual std::string getName()=0;
    virtual std::string breed()=0;
protected:
    std::string _name;
    int _age;
    int _weight;
};


#endif //INC_03ZOO_ANIMAL_H
