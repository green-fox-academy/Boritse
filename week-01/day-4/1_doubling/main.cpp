#include <iostream>
#include <string>

int doubling(int x){
    x*=2;
    return x;
}

int main(int argc, char* args[]) {

    int baseNum=123;
    std::cout << doubling(baseNum) << std::endl;

    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`

    return 0;
}