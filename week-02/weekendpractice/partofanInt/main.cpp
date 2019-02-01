#include <iostream>
#include <vector>

int main(int argc, char* args[])
{
    //  Create a function that takes a number and a vector of numbers as a parameter
    //  Returns the indeces of the numbers in the vector where the first number is part of
    //  Returns an empty list if the number is not part any of the numbers in the vector

    //  Example:
    std::vector<int> numbers = {1, 11, 34, 52, 61};
    subInt(1, numbers);
    //  should print: `[0, 1, 4]`
    subInt(1, numbers);
    //  should print: '[]'

    return 0;
}