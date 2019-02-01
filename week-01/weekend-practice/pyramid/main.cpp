#include <iostream>

int main(int argc, char* args[]) {

    int x;
    std::cout << "Number please" << std::endl;
    std::cin >> x;
    std::string w= "*";

    for(int y=0; y<x; y++){
        for(int z=y+(x-1)-(y*2); z>0; z-=1) {
            std::cout << " ";
        }
            for (int k = 1; k <= (2 * y - 1); k++) {
                std::cout << w;
            }
        std::cout << std::endl;
    }
    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    return 0;
}