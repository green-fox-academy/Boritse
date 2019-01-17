#include <iostream>
#include <string>

int swap(int& x, int& y){
    int k;
    k=x;
    x=y;
    y=k;
}

int main(int argc, char* args[]) {

   int a=15;
   int b=23;

   std::cout << a << " " << b << std::endl;

   swap(a,b);

   std::cout << a << " " << b << std::endl;

    // Create two integer variables: a=15, b=23
    // Create a function named swap that gets the 2 integers as parameters and swaps its values.
    // Print the values before and after the function call and make sure the values are printed in reversed order.

    return 0;
}