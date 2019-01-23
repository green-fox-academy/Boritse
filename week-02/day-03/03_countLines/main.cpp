#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main () {
    std::ofstream myFile;
    myFile.open("my-file.txt");

    if (myFile.is_open()) {
        myFile << "Baby's good to me, you know" << std::endl;
        myFile << "She's happy as can be, you know" << std::endl;
        myFile << "She said so" << std::endl;
        myFile << "I'm in love with her and I feel fine" << std::endl;
    } else {
        std::cout << "The file is unfortunately not open";
    }

    myFile.close();

    std::ifstream mySecondFile("my-file.txt");
    std::vector<std::string> linesVector;
    std::string lines;

    if (mySecondFile.fail()) {
        std::cerr << "Error opening file" << std::endl;
    }

    if (mySecondFile.is_open()) {
        int z = 0;
        while (std::getline(mySecondFile, lines)) {
            linesVector.push_back(lines);
        }
        for (int i = 0; i < linesVector.size(); i++) {
            z = i+1;
        }
        std::cout << "The file contains " << z << " lines.";
    }else {
        std::cout << "not open";
    }

    mySecondFile.close();

    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    return 0;
}