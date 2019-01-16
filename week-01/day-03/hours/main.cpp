#include <iostream>

int main(int argc, char* args[]) {
    int dhours=6;
    int weeks=17;
    int alldays= weeks*5;
    std::cout << alldays*dhours << std::endl;
    float weeklywork=52;
    float weeklycoding=dhours*5;
    std::cout << weeklycoding/weeklywork*100 << std::endl;
    return 0;
}