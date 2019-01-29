//
// Created by Borbáls on 2019. 01. 29..
//

#ifndef ANIMALS_ANIMALS_H
#define ANIMALS_ANIMALS_H

#include <string>

class animals {
public:
    animals();

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


#endif //ANIMALS_ANIMALS_H
