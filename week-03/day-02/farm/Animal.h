//
// Created by Borbáls on 2019. 01. 30..
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

#include <string>

class Animal {
public:
    Animal();

    void eat();
    void drink();
    void play();

    int getHunger();
    int getThirst();

private:
    std::string type;
    int hunger;
    int thirst;

};


#endif //ANIMAL_ANIMAL_H
