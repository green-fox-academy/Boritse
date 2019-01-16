#include <iostream>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string username;

    std::cout << "Please tell me your name:) " << std::endl;
    std::cin >> username;
    std::cout << "Hello, " << username << " :)!" << std::endl;

    return 0;
}