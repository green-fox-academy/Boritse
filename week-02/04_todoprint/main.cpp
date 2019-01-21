#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string todoText = " - Buy milk\n";

    std::string beginning= "My todo:\n";
    std::string download= " - Download games\n";
    std::string diablo= "    - Diablo\n";

    todoText.insert(0, beginning);
    todoText+=download;
    todoText+=diablo;
    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    std::cout << todoText << std::endl;

    return 0;
}