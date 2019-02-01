#include <iostream>

int main(int argc, char* args[]) {

    int x;
    int y;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> x;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> y;

    int numberoflegs= x*2 + y*4;

    std::cout << "The number of legs in the farm are: " << numberoflegs;
// Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    return 0;
}