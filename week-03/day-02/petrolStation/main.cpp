#include <iostream>
#include "station.h"
#include "car.h"

int main() {

    station s(1221);
    car car1(75, 100);
    car car2(92, 98);
    car car3(99, 99);
    car car4(43, 57);

    s.fill(car1);
    std::cout << car1.getGasAmount() << std::endl;

    s.fill(car2);
    std::cout << car2.getGasAmount() << std::endl;

    s.fill(car3);
    std::cout << car3.getGasAmount() << std::endl;

    s.fill(car4);
    std::cout << car4.getGasAmount() << std::endl;

return 0;
}