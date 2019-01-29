#include <iostream>
#include "sharpie.h"

int main() {

    sharpie thingy("blue", 3.2);

    std::cout << thingy.use();

    return 0;
}