#include <iostream>

int main(int argc, char* args[]) {

    int y=8;
    std::string sor1= "%";
    std::string sor2= " ";

    for(int x=1; x<=y; x++) {
        if (x % 2 == 1) {
            sor1 += " ";
            sor2 += "%";
        } else {
            sor2 += " ";
            sor1 += "%";
        }
    }
    for(int x=1; x<=y; x++) {
        if(x%2==1){
            std::cout << sor1 << std::endl;
            }else{
            std::cout << sor2 << std::endl;
            }
        }
}



// Crate a program that draws a chess table like this
//
// % % % %
//  % % % %
// % % % %
//  % % % %
// % % % %
//  % % % %
// % % % %
//  % % % %
