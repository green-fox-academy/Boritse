#include <iostream>
#include <string>

std::string appendAFunc(std::string x){
    return x+"a";
}


int main(int argc, char* args[]) {

    std::string typo= "Chinchill";
    appendAFunc(typo);
    std::string returnString= appendAFunc(typo);
    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`
    std::cout << returnString << std::endl;
    return 0;
}