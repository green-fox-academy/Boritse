#include <iostream>
#include <string>
#include "animals.h"

int main() {

    animals kutya;

    for(int i=0; i<5; i++){
        kutya.play();
        kutya.drink();
    }

    std::cout << "The current level of hunger of Blöki is: " << kutya.getHunger() << std::endl;
    std::cout << "The current level of thirst of Blöki is: " << kutya.getThirst() << std::endl;

    return 0;
}