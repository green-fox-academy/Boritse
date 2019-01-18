#include <iostream>

int main(int argc, char* args[]) {

    int x;
    std::string szazalek= "%";
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> x;

    for(int z=1; z<=x; z++){
        szazalek+="%";
        if(z==x){
            for(int y=1; y<=x; y++){
                std::cout << szazalek << std::endl;
            }
        }
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