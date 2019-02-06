//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef FLYABLE_ANIMALS_H
#define FLYABLE_ANIMALS_H

#include <string>

class Animals {
public:
    Animals();

    void eat();
    void drink();
    void play();

    int getHunger();
    int getThirst();

protected:
    std::string type;
    int hunger;
    int thirst;

};


#endif //FLYABLE_ANIMALS_H
