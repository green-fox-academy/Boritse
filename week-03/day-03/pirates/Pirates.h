//
// Created by Borbáls on 2019. 02. 02..
//

#ifndef PIRATES_PIRATES_H
#define PIRATES_PIRATES_H


#include <richedit.h>

class Pirates {
public:
    Pirates();
    void drinkSomeRum();
    void howsItGoingMate();
    int getlevelOfRum();
    bool die();
    void deadMessage();
    int getTimesOfDrinking();
private:
    int levelOfRum;
    int timesOfDrinking;
    bool alive;
};


#endif //PIRATES_PIRATES_H
