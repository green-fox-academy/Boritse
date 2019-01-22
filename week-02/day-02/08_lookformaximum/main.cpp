#include <iostream>


int main()
{
    int x;
    std::cout << "How many integers do you want me to store in my array?" << std::endl;
    std::cin >> x;

    int myArray[x];
    for(int i=0; i<x; i++){
        std::cout << "Number pls" << std::endl;
        std::cin >> myArray[i];
    }

    int* p_myArray = myArray;
    int y=0;
    int z=0;
    for(int i=0; i<x; i++){
        if(myArray[i]>y){
            y=myArray[i];
            z=i;
        }
    }

    std::cout << "The biggest number in the array is: " << *(p_myArray + z) << std::endl;
    std::cout << "The memory address of the bigest number is: " << p_myArray + z ;


    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    return 0;
}