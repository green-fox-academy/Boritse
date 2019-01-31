#include <iostream>

std::string swapper(std::string something, int letters){
    if(letters==0){
        return something;
    }else{
        if (something[letters - 1]== 'x') {
            something[letters - 1] = 'y';
        }
        return swapper(something, letters - 1);
    }
    return 0;
}

int main() {
    std::cout << swapper("Thank you Adam xoxo", 19);
    return 0;
}