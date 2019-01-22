#include <iostream>

int indexFinder(int *array, int size, int x){
    for(int i=0; i<size; i++){
        if(array[i]==x){
            return i;
        }
    }
    return 0;
}

int main()
{
    int myArray[]= {23, 432, 65, 32, 64, 543, 34};
    int sizeOfMyArray = sizeof(myArray)/sizeof(myArray[0]);
    int y;
    std::cout << "Which number should we look for in our array?" << std::endl;
    std::cin >> y;

    std::cout << indexFinder(myArray, sizeOfMyArray, y);
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    return 0;
}