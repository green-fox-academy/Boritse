#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number paramter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

void writeToFile(std::string path, std::string word, int number){

    std::string workingFile = path + "working-file.txt";
    std::ofstream workingFile1(workingFile);
    std::cout << "Give me a line ";
    std::cin.ignore();
    std::getline(std::cin, word,'\n');
    for(int i=0; i<number; i++){
        workingFile1 << word << std::endl;
    }
}

int main() {

    std::string pathOfFile= "./";
    int numberOfLines=0;
    std::cout << "How many lines should my file have?";
    std::cin >> numberOfLines;
    std::string contentOfLines;
    writeToFile(pathOfFile, contentOfLines, numberOfLines);
    return 0;
}
