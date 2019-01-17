#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int aj[5]={3,4,5,6,7};
    int bj[5];
    int y=5;

    for (int x=0; x<5; x++){
        y=y-1;
        bj[x]=aj[y];
    }

    std::cout << bj[0] << " " << bj[1] << " " << bj[2] << " " << bj[3] << " " << bj[4] << std::endl;
    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    return 0;
}