#include <iostream>

#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;

    Thing milk("Get milk");
    Thing obstacle("Remove the obstacles");
    Thing stand("Stand up");
    stand.complete();
    Thing lunch("Eat lunch");
    lunch.complete();

    fleet.add(milk);
    fleet.add(obstacle);
    fleet.add(stand);
    fleet.add(lunch);

    milk.toString();
    obstacle.toString();
    stand.toString();
    lunch.toString();

    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    std::cout << fleet.toString() << std::endl;
    return 0;
}