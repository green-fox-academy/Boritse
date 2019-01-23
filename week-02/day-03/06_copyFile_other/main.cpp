#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>


void copier(std::string originalFile, std::string copyFile);

int main(){

    std::string file1="original.txt";
    std::string file2="copy.txt";
    copier(file1, file2);

    return 0;
}

void copier(std::string originalFile, std::string copyFile){

    std::string lines;
    std::ifstream readOutFile(originalFile);
    std::ofstream writeInFile(copyFile);

    while(std::getline(readOutFile, lines)){
        writeInFile << lines << std::endl;
        std::cout << lines << std::endl;
    }
    writeInFile.close();
    readOutFile.close();

}