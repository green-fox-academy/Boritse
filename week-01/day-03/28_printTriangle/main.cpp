#include <iostream>

int main(int argc, char* args[]) {

    int x;
    std::string w= "*";
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> x;

    for(int y=1; y<=x; y++){
        w+="*";
        std::cout << w << std::endl;
    }


    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    return 0;
}