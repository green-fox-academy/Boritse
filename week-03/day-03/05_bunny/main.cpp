#include <iostream>

int countsEars(int bunnies){
    if(bunnies==1){
        return 2;
    }else{
        return 2+countsEars(bunnies - 1);
    }
    return 0;
}

int main() {
    std::cout << countsEars(27);
}