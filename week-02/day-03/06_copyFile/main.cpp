#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copier(std::string firstFile, std::string secondFile){

    std::string lines;
    std::vector<std::string> contentOfFile;

    std::ifstream originFile(firstFile);
    while(originFile >> lines){
        contentOfFile.push_back(lines);
    }
    originFile.close();

    std::ofstream recieverFile(secondFile);
    for(int i=0; i<contentOfFile.size(); i++){
        recieverFile << contentOfFile[i];
    }
    recieverFile.close();

    std::string lineChecker;
    int lineCounter = 0;
    int lineCounter2 = 0;
    originFile.open(firstFile);
    while(std::getline(originFile, lineChecker)){
        lineCounter+=1;
    }
    originFile.close();

    std::ifstream recieverFileIn(secondFile);
    recieverFileIn.open(secondFile);
    while(std::getline(recieverFileIn, lineChecker)){
        lineCounter2+=1;
    }
    recieverFile.close();
    if(lineCounter==lineCounter2){
        return true;
    }else{
        return false;
    }
}

int main() {

    std::string path = "./";
    std::string myFirstFile = path+"origin-file.txt";
    std::string mySecondFile = path+"destination-file.txt";

    std::string content;
    std::cout << "please give some content to my first file" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, content);

    copier(myFirstFile, mySecondFile);

    return 0;
}