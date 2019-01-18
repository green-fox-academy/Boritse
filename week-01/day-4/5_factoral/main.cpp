#include <iostream>
#include <string>

int factorio(int& x, int& y){
    int w=1;
    for(int z=1; z<=x; z++){
        w*=z;
    }
    y=w;
}

int main(int argc, char* args[]) {

    int x=4;
    int y=7;
    factorio(x,y);
    std::cout << x << " " << y << std::endl;
    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    return 0;
}