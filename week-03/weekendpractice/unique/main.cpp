#include <iostream>
#include <string>

int unique(int x, int duplicatesPresent[x])
{
    std::sort(duplicatesPresent.begin(), duplicatesPresent.end());
    duplicatesPresent.erase(std::unique(duplicatesPresent.begin(), duplicatesPresent.end()), duplicatesPresent.end());

    return duplicatesPresent[];
}

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int x=0;
    while (x!= sizeof(numbers)){
        x++;
    }
    std::cout << (unique(x, numbers)) << std::endl;
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}