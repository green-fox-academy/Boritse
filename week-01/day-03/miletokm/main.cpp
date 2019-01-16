#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    int km;
    std::cout << "Please tell me the distance run in kms!" << std::endl;
    std::cin >> km;
    float mile=1.6*km;
    std::cout << "The distance you ran in miles is no less than " << mile << "!" << std::endl;

    return 0;
}