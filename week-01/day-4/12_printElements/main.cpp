#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int numbers[]={4,5,6,7};

    for(int x=0; x<4; x++){
        std::cout << numbers[x] << std::endl;
    }
    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    return 0;
}