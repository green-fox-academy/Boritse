#include <iostream>
#include <string>

void sizeCompare(int x[], int y[]){

    bool valtozo=(sizeof(x)/sizeof(x[0]) > sizeof(y)/sizeof(y[0]));
    if (valtozo){
        std::cout << x << " has more elements than " << y << std::endl;
    }else{
        std::cout << y << " has more elements than " << x << std::endl;
    }
}

int main(int argc, char* args[]) {

    int p1[]={1,2,3};
    int p2[]={4,5};

    sizeCompare(p1, p2);
    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`

    return 0;
}