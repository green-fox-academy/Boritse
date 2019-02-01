#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int rawscolumns;
    std::cout << "Give me the number of rows and columns you want!" << std::endl;
    std::cin >> rawscolumns;
    int array[rawscolumns][rawscolumns];

    for(int x=0; x<rawscolumns; x++){
        for(int y=0; y<rawscolumns; y++)
        if(x==y){
            std::cout << 1 << " ";
        }else {
            std::cout << 0 << " ";
        }
        std::cout << std::endl;
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