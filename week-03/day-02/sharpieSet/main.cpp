#include <iostream>
#include "sharpie.h"
#include "sharpieSet.h"

int main() {

    sharpieSet mySharpies;
    mySharpies.fillMyVect();

    std::cout << mySharpies.countUsuable() << std::endl;

    mySharpies.useSharpie(1);
    mySharpies.useSharpie(1);
    mySharpies.useSharpie(1);
    mySharpies.useSharpie(1);

    mySharpies.removeTrash();

    std::cout << mySharpies.countUsuable();
}