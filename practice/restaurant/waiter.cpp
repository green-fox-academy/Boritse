//
// Created by Borbáls on 2019. 02. 13..
//

#include "Waiter.h"

Waiter::Waiter() : Employee(){
    _tip=0;
    _type="waiter";
}
Waiter::Waiter(int experience) : Employee(experience){
    _tip=0;
    _type="waiter";
}
void Waiter::work(){
    _tip++;
    _experience++;
}