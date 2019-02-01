#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char* args[])
{
    std::vector<std::string> operations={"+", "-", "*", "/", "%"};
    std::string userInput;
    std::string operatorInput;
    std::string aa;
    int a;
    std::string bb;
    int b;

    std::cout << "Please type in the operation needed and the two operands, each expression divided by a space!" << std::endl;
    std::getline(std::cin, userInput);

    std::cout << "thank you" << std::endl;

    std::istringstream userInputPieces(userInput);

    while(std::getline(userInputPieces, userInput)){
        std::getline(userInputPieces, operatorInput, ' ');
        std::getline(userInputPieces, aa, ' ');
        std::getline(userInputPieces, bb, ' ');
    }

    std::cout << operatorInput << " " << aa << " " << bb;

//   a = std::stoi(aa, nullptr);
//   b = std::stoi(bb, nullptr);

//    for(int i=0; i<operations.size(); i++){
//        if(operations[i]==operatorInput){
//            std::cout << a << operations[i] << b;
//        }
//    }

    return 0;
}