#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char* args[])
{
    //  Create a function that takes a string and a vector of string as a parameter
    //  Returns the index of the string in the vector where the first string is part of
    //  Only need to find the first occurence and return the index of that
    //  Returns `-1` if the string is not part any of the strings in the vector

    std::vector<std::string> searchArr = {"this", "is", "what", "I'm", "searching"};
    std::string substring="arc";

    for(int i=0; i<searchArr.size(); i++){
        std::size_t found = searchArr[i].find(substring);
        if(found!=std::string::npos){
            std::cout << "The index of the string where the substring is found: " << found;
            break;
        }else if(i==searchArr.size()-1){
            std::cout << "-1 - I'm sorry but substring wasn't found";
        }
    }


    //  Example:

    //subStrList("ching", searchArr);
    //  should print: `4`
    //subStrList("not", searchArr);
    //  should print: `-1`
    //
    return 0;
}