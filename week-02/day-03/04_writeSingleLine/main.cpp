#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ofstream fileWithMyName("my-file.txt");
    fileWithMyName << "Borbala Szakacs";

    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    return 0;
}