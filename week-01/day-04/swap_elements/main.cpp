#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    std::string abc[3]={"first", "second", "third"};
    std::string b=abc[0];
    abc[0]=abc[2];
    abc[2]= b;

    std::cout << abc[0] << " " << abc[1] << " " << abc[2] << std::endl;

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`

    return 0;
}