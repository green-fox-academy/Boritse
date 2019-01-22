#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> quoteSwap(std::vector<std::string> &functionVector){
    std::vector<std::string> helper;
    helper.push_back(functionVector[2]);
    helper.push_back(functionVector[5]);
    functionVector.erase(functionVector.begin() +5);
    functionVector.erase(functionVector.begin() +2);
    functionVector.insert(functionVector.begin() +2, helper[1]);
    functionVector.insert(functionVector.begin() +5, helper[0]);
    return functionVector;
}

int main(int argc, char* args[])
{
    std::vector<std::string> quote = {"What", "I", "do", "create,", "I", "cannot", "not", "understand."};

    quoteSwap(quote);

    for(int i=0; i<quote.size(); i++){
        std::cout << quote[i] << " ";
    }


    // Accidentally I messed up this quote from Richard Feynman.
    // Two words are out of place
    // Your task is to fix it by swapping the right words with code
    // Create a method called quoteSwap().

    // Also, print the sentence to the output with spaces in between.

    return 0;
}