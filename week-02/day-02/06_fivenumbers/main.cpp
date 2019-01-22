#include <iostream>

int main()
{
    int array[5];
    for(int i=0; i<5; i++){
        std::cout << "Please give me the " << i+1 << ". number!" << std::endl;
        std::cin >> array[i];
    }

    int *p_array = array;
    for(int i=0; i<(sizeof(array)/sizeof(array[0])); i++)
        std::cout << *(p_array + i) << std::endl;
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    return 0;
}