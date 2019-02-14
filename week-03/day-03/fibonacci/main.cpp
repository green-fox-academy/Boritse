#include <iostream>

int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        n=fibonacci(n-1)+fibonacci(n-2);
    }
    return n;
}

int main() {
    std::cout << fibonacci(17);
    return 0;
}