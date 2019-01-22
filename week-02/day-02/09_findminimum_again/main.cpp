#include <iostream>

int* minimumValue(int* array, int size){
    int z=0;
    for(int i=0; i<size; i++){
        if(array[i]<array[z]){
            z=i;
        }
    }
    int* p_arrayMinimum=&array[z];
    std::cout << *p_arrayMinimum << std::endl;
    return p_arrayMinimum;
}

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int lengthOfNumbers = sizeof(numbers)/sizeof(numbers[0]);

    std::cout << minimumValue(numbers, lengthOfNumbers);

    return 0;
}