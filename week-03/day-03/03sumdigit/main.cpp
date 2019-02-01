#include <iostream>

int digitSum(int n){
    if(n<0){
        std::cout << "aint your program, mate";
    }else{
        return n%10+digitSum(n/10);
    }
    return 0;
}

int main() {
    std::cout << digitSum(17);
    return 0;
}