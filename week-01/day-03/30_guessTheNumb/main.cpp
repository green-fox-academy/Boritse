#include <iostream>

int main(int argc, char* args[]) {

    int x = 17;
    int y;

    std::cout << "Guess the number if you dare:)!" << std::endl;
    std::cin >> y;

    while (y != x) {
        if (y > x) {
            std::cout << "The stored number is lover!" << std::endl;
        } else {
            std::cout << "The stored number is higher!" << std::endl;
        }
        std::cout << "Now you can try again!" << std::endl;
        std::cin >> y;
    }

    if (y == x) {
        std::cout << "You found the number: " << x << ", well done:)!"<< std::endl;
    }


    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    return 0;
}