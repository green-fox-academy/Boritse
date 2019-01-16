#include <iostream>

int main(int argc, char* args[]) {

    int szam;
    std::cout << "Please give me a number!:)" << std::endl;
    std::cin >> szam;
    if(szam<=0){
        std::cout << "I'm awfully sorry but this number is too small." << std::endl;
    }else if(szam==1){
        std::cout << "The number you gave me is exactly one." << std::endl;
    }else if(szam==2){
        std::cout << "The number you gave me is exactly two." << std::endl;
    }else{
        std::cout << "The number you gave me is huuuuge." << std::endl;
    }
    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot

    return 0;
}