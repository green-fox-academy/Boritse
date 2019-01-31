#include <iostream>

int toPower(int x, int n){
    if(x<=0 || n<=0){
        std::cout << "sorry mate but i need positive numbers";
    }else if(n==1){
        return x;
    }else{
        return x*toPower(x, n-1);
    }
    return 0;
}

int main() {
    std::cout << toPower(3, 4);
    return 0;
}