#include <iostream>

int main()
{
    int array[5];
    for(int i=0; i<5; i++){
        std::cout << "Give me a number" << std::endl;
        std::cin >> array[i];
    }

    int *p_array = array;
    for(int i=0; i<(sizeof(array)/sizeof(array[0])); i++)
        std::cout << p_array + i << std::endl;
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    return 0;
}