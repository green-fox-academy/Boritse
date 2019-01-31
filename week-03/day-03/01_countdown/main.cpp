#include <iostream>

int countdown(int n){
    if(n<=0){
        std::cout << "The number is too low for this excercise, fuck off" << std::endl;
    }else if(n==1){
        return n;
    }else{
        std::cout << n << std::endl;
        return countdown(n-1);
    }
}

int main() {
    std::cout << countdown(9);
}