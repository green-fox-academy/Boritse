#include <iostream>

int earCounter(int bunnies){
    if(bunnies<1){
        std::cout << "no bunnies no ears";
    }
    else if(bunnies==1){
        return 2;
    }
    else if(bunnies%2==0){
        return 3+earCounter(bunnies-1);
    }else{
        return 2+earCounter(bunnies-1);
    }
    return 0;
}

int main() {
    std::cout << earCounter(7);
    return 0;
}