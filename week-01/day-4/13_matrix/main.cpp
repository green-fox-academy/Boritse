#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    std::cout << "How many rows and columns should my matrix have?" << std::endl;
    int x;
    std::cin >> x;
    int array[x][x];

    for (int y=0; y<x; y++){
        for (int w=0; w<x; w++){
            if (y==w){
                array[y][w]=1;
            }else{
                array[y][w]=0;
            }
            std::cout << array[y][w] << std::endl;
        }
    }

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    return 0;
}
