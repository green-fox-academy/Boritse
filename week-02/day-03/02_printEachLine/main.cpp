#include <iostream>
#include <fstream>
#include <string>

int main () {

    std::ofstream myFile;
    myFile.open("my-file.txt");

    if(myFile.is_open()){
        myFile << "Baby's good to me, you know" << std::endl;
        myFile << "She's happy as can be, you know" << std::endl;
        myFile << "She said so" << std::endl;
        myFile << "I'm in love with her and I feel fine" << std::endl;
    }else {
        std::cout << "The file is unfortunately not open";
    }

    myFile.close();

    std::ifstream mySecondFile("my-file.txt");
    std::string lines;

    if(mySecondFile.fail()){
        std::cerr << "Error opening file" << std::endl;
    }

    while(std::getline(mySecondFile, lines)){
        std::cout << lines << std::endl;
    }

    mySecondFile.close();


    // Write a program that opens a file called "my-file.txt", then prints
    // each of lines form the file.
    // You have to create the file, you can use C-programming but it is not mandatory


    return 0;
}