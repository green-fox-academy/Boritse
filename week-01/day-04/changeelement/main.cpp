#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int s[6]={1,2,3,8,5,6};
    s[3]=4;
    std::cout << s[3] << std::endl;
    std::cout << s[0] << s[1] << s[2] << s[3] << s[4] << s[5] << std::endl;

    return 0;
}