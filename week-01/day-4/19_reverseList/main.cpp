#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int aj[5]={3,4,5,6,7};
    int y=5;
    int bj[5];
    for(int x=0; x<5; x++){
        y=y-1;
        bj[x]=aj[y];
        std::cout << bj[x] << std::endl;
    }
    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    return 0;
}