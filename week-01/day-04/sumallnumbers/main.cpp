#include <iostream>
#include <string>

int fuggv(int szam){
    int szum=0;
    for(int x=1; x<szam; x++){
    szum+=x;
    }
    return szum;
}

int main(int argc, char* args[]) {

    fuggv(100);

    std::cout << fuggv(100) << std::endl;
    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer

    return 0;
}