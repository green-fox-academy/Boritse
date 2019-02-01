#include <iostream>
#include <string>

int  barmi(int (&nL)[5]);

int main(int argc, char* args[]) {

    int numList[]={3,4,5,6,7};

    barmi(numList);

    for(int x=0; x<5; x++){
        std::cout << numList[x] << std::endl;
    }
    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    return 0;
}

int barmi(int (&nL)[5]){
    for (int x=0; x<5; x++){
        nL[x]*=2;
    }
    return nL[5];
}