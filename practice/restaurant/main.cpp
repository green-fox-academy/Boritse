#include <iostream>
#include "restaurant.h"
#include "waiter.h"
#include "chef.h"
#include "manager.h"

int main() {

    Waiter Snocc(35);
    Chef Adam;
    Manager Dani(20);
    Waiter Peti(24);

    Restaurant resti("BoroRestaurant", 1989);

    resti.hire(Snocc);
    resti.hire(Adam);
    resti.hire(Dani);
    resti.hire(Peti);

    Adam.cook("pizza");
    Adam.cook("pizza");
    Adam.cook("pizza");
    Adam.cook("steak");
    Adam.cook("steak");

    resti.guestsArrived();
    resti.getExperience();


    return 0;
}