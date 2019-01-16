#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    int szam;

    std::cout << "What's your favourite number?" << std::endl;
    std::cin >> szam;

    if (szam%2==0){
        std::cout << "Your favourite number is even! :)" << std::endl;
    }else{
        std::cout << "Your favourite number is odd! :)" << std::endl;
    }

    return 0;
}
