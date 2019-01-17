#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int numList[]={3,4,5,6,7};

    for (int x=0; x<5; x++){
        numList[x]*=2;
        std::cout << numList[x] << std::endl;
    }
    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    return 0;
}