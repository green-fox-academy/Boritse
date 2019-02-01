#include <iostream>

void swapper(int &firstNumber, int &secondNumber){
    int helper = firstNumber;
    firstNumber = secondNumber;
    secondNumber = helper;
}

int main ()
{
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;

    std::cout << "The value of a is: " << a << ", and the value of b is: " << b << std::endl;

    int* p_a = &a;
    int* p_b = &b;

    swapper(*p_a, *p_b);

    std::cout << "And now the value of a is: " << a << ", and the value of b is: " << b;

    return 0;
}