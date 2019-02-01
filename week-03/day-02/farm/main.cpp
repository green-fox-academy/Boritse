#include <iostream>
#include "Farm.h"
#include "Animal.h"

int main() {

    Farm myFarm;

    myFarm.breed();
    myFarm.breed();
    myFarm.breed();

    myFarm.play(1);
    myFarm.play(2);
    myFarm.feed(0);

    myFarm.slaughter();

    myFarm.currentNumberOfSlots();
}