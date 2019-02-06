#include <iostream>
#include "helicopter.h"
#include "Bird.h"

int main() {

    Helicopter helikopi;
    helikopi.takeoff();
    helikopi.fly();
    helikopi.move();
    helikopi.land();

    Bird birdyy;
    birdyy.eat();
    std::cout << birdyy.getHunger() << std::endl;
    birdyy.fly();


    return 0;
}


