#include <iostream>
#include <string>

int sum(int x){
    int y=0;
    for(int z=0; z<=x; z++){
        y+=z;
    }
    return y;
}

int main(int argc, char* args[]) {

    sum(17);
    std::cout << sum(17) << std::endl;
    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer

    return 0;
}