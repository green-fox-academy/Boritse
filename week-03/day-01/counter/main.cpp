#include <iostream>
#include "counter.h"

int main() {

    counter bubu;
    bubu.add();
    bubu.ADD(17);

    std::cout << "The actual state of the counter: " << bubu.get();

}