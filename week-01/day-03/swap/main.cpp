#include <iostream>

int main(int argc, char* args[]) {
    int a=123;
    int b=526;
    int c=a;
    a=b;
    b=c;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}