#include <iostream>
#include <vector>
#include "Pirates.h"
#include "Ship.h"

int main() {
    
        Pirates CaptainGoods;
        Pirates CaptainBads;
        Ship ShipGoods;
        Ship ShipBads;

        ShipGoods.fillShip(CaptainGoods);
        ShipBads.fillShip(CaptainBads);

        std::cout << ShipGoods.aliveCrew() << std::endl;
        std::cout << ShipBads.aliveCrew() << std::endl;

}