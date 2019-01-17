#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    std::string animals[]={"koal", "pand", "zebr"};
    for(int x=0; x<3; x++){
        animals[x]+="a";
        std::cout << animals[x] << std::endl;
    }
    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    return 0;
}