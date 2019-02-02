#include <iostream>
#include <vector>

int main(int argc, char* args[]) {

    int userInput;
    std::cout << "Please provide me with a positive integer!:)";
    std::cin >> userInput;

    std::vector<int> allInputs;

    for(int i=0; i<userInput; i++){
        int x=userInput-(i+1);
        int y;
        std::cout << "Please give me another number! (there are " << x << " more to go!" << std::endl;
        std::cin >> y;
        allInputs.push_back(y);
    }

    double sum=0;

    for(int i=0; i<allInputs.size(); i++){
        sum+=allInputs[i];
    }

    double average=sum/userInput;

    std::cout << "Sum: " << sum << ", Average: "<< average;

    return 0;
}
