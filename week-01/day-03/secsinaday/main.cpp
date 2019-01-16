#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    int secondstotal= 24*60*60;
    int goneseconds= currentHours*60*60+currentMinutes*60+currentSeconds;

    std::cout << secondstotal << std::endl;
    std::cout << goneseconds << std::endl;
    std::cout << secondstotal-goneseconds << std::endl;

    return 0;
}