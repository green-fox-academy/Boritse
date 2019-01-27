#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string ticTacResult(std::string fileName)
{
    std::ifstream workingFile(fileName);

    std::vector<char> columnOne;
    std::vector<char> columnTwo;
    std::vector<char> columnThree;
    char tic;
    char tac;
    char tictac;

    std::string theWinner;

    while(workingFile >> tic >> tac >> tictac){
        columnOne.push_back(tic);
        columnTwo.push_back(tac);
        columnThree.push_back(tictac);
    }

    for(int i=0; i<columnOne.size(); i++){
        if((columnOne[i]==columnTwo[i]==columnThree[i])){
            theWinner=columnOne[i];
        }
    }

    if(columnOne[0]==columnOne[1]==columnOne[2]){
        theWinner=columnOne[0];
    }else if(columnTwo[0]==columnTwo[1]==columnTwo[3]){
        theWinner=columnTwo[0];
    }else if(columnThree[0]==columnThree[1]==columnThree[3]) {
        theWinner = columnThree[0];
    }else if(columnOne[0]==columnTwo[1]==columnThree[2]){
        theWinner = columnOne[0];
    }else if(columnOne[2]==columnTwo[1]==columnThree[0]){
        theWinner = columnOne[2];
    }else{
        theWinner = "This is a draw.";
    }



return theWinner;
}

int main() {
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::string winnerO = "win-o.txt";
    std::string winnerX = "win-x.txt";
    std::string draw = "draw.txt";

    std::cout << "The winner is: " << ticTacResult(winnerO);
    // should print O

    std::cout << "The winner is: " << ticTacResult(winnerX);
    // should print X

   std::cout << ticTacResult(draw);
    // should print draw

    return 0;
}