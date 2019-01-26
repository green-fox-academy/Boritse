#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    int maxValue;
    int guess;

    std::cout << "Give me the maximum of the positive number I should think of, you'll have five opportunities to guess it!" << std::endl;
    std::cin >> maxValue;

    srand(time(0));
    int myNumber=(rand()%maxValue);

    int lives=5;
    std::cout << "I have the number between 1-" << maxValue << ". You have " << lives << " lives." << std::endl;

    for(int i=0; i<5; i++) {
        std::cin >> guess;
        if (myNumber > guess) {
            std::cout << "Too low. You have " << lives-i-1 << " lives left" << std::endl;
        }else if(myNumber < guess){
            std::cout << "Too high. You have " << lives-i-1 << " lives left" << std::endl;
        }else{
            std::cout << "Congratulations, You won!";
        }
    }

    return 0;
}