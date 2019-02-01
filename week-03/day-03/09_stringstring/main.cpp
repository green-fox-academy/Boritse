#include <iostream>
#include <algorithm>

std::string adjacent(std::string something, int letters){
    if(letters==letters*2-1){
        return something;
    }else{
        something.insert(letters-2, '*');
        return adjacent(something, letters+1 - 2);
    }
    return 0;
}

int main() {
    std::cout << adjacent("Thank you Adam xoxo", 19);
    return 0;
}