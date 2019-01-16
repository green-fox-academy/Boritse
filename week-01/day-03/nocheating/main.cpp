#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // Create a program that writes this line 100 times:
    // "I won't cheat on the exam!"

    std::string line;
    line= "I won't cheat on the exam";

    for (int i = 0; i < 100 ; i++) {
        std::cout << line << std::endl;
    }

    return 0;
}