#include <iostream>
#include <fstream>
#include <exception>
#include <string>

int main() {

    float x=10;
    float divider;

    std::cout << "What should I divide 10 by?" << std::endl;
    std::cin >> divider;

    try {
        if (divider == 0) {
            throw 666;
        }
        std::cout << x / divider << std::endl;
    }catch (int x)
        {
            std::cout << "fail" << std::endl;
        }

    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    return 0;
}