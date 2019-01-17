#include <iostream>
#include <string>

void fuggv(std::string barmi[]){
    for (int x=0; x<3; x++){
        barmi[x]+="a";
    }
}

int main(int argc, char* args[]){

    std::string animals[3]={"koal", "pand", "zebr"};

    fuggv(animals);

    std::cout << animals[0] << " " << animals[1] << " " << animals[2] << std::endl;
    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    return 0;
}