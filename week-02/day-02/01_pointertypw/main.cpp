#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *p_a = &a;
    double *p_b = &b;
    std::string *p_name = &name;

    std::cout << "The value of p_a is: " << p_a << std::endl;
    std::cout << "The value of p_b is: " << p_b << std::endl;
    std:: cout << "The value of p_name is: " << p_name;

    return 0;
}