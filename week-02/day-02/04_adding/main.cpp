#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;
    int sum;

    int *p_a = &a;
    int *p_b = &b;
    sum = *p_a + *p_b;

    std::cout << "The sum of the two integers is: " << sum;

    return 0;
}