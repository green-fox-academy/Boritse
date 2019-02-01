#include <iostream>
#include <vector>

int main() {
    int numberToCheck;
    std::cout << "Let me check if the number on your mind is an Armstrong number! Which number is on your mind?" << std::endl;
    std::cin >> numberToCheck;
    int numberToCheckhelp=numberToCheck;

    std::vector<int> digits;
    int digit=0;

    while(numberToCheckhelp>0){
        digit = numberToCheckhelp%10;
        numberToCheckhelp/=10;
        digits.push_back(digit);
    }

    int armstrong=0;

    for(int i=0; i<digits.size(); i++){
        int currentDigit=1;
        for(int j=0; j<digits.size(); j++){
            currentDigit*=digits[i];
        }
        armstrong+=currentDigit;
    }

    if(numberToCheck==armstrong){
        std::cout << "You are a lucky man, your number is an Armstrong number!";
    }else{
        std::cout << "Sorry to say but your number is not an Armstrong number.";
    }
    return 0;
}