#include <iostream>
#include <string>

int factorio(int input){
    int y=1;
    for(int x=1; x<=input; x++){
        y*=x;
    }
    return y;
}

int main(int argc, char* args[]) {

    factorio(12);

    std::cout << factorio(12) << std::endl;
    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    return 0;
}