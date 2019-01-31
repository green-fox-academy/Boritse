#include <iostream>

int adder(int n){
    if(n<=0){
        std::cout << "Please give me a positive number, otherwise my memory will crash" << std::endl;
    }else if(n==1){
        return 1;
    }else{
        return n=n+adder(n-1);
    }
    return 0;
}

int main() {
    std::cout << adder(18);
    return 0;
}