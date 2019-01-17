#include <iostream>
#include <string>

int sum(int szam){
    for(int x=1; x<szam; x+=x) {
        std::cout << x << std::endl;
    }
}

int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer
    sum(30);


    return 0;
}
© 2019 GitHub, Inc.