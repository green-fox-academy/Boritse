#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int ai[5]={3,4,5,6,7};
    int sum=0;
    for (int x=0; x<5; x++) {
        sum+=ai[x];
        std::cout << sum << std::endl;
    }
    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`

    return 0;
}