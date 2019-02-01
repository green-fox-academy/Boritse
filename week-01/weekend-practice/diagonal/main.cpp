#include <iostream>

int main(int argc, char* args[]) {

    int x;
    std::cout << "Please, I need a number so bad, can you give it to me?" << std::endl;
    std::cin >> x;

    for(int y=1; y<=x; y++) {
        for (int z = 1; z <= x; z++) {
            if ((y==1) || (z==1) || (y == x) || ( z== x) || (z == y)) {
                std::cout << "&";
            }else{
            std::cout << " ";
        }
    }
        std::cout << std::endl;
}
    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was

    return 0;
}