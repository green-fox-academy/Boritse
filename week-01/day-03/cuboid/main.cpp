#include <iostream>

int main(int argc, char* args[]) {

    double a=7;
    double b=13;
    double c=17;

    double volume=a*b*c;
    double surface=2*(a*b + b*c + a*c);

    std::cout << "Surface area: " << surface << std::endl;
    std::cout << "Volume: " << volume;
// Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    return 0;
}