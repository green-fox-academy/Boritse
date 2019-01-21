#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> makingMatches(const std::vector<std::string>& girls, const std::vector<std::string>& boys) {
    int length1= boys.size();
    int length2=girls.size();
    int length=length1+length2;
    std::vector<std::string> pairs;
    int x=0;
    int y=0;
    for (int i = 0; i < length; i++) {
            if (i % 2 == 0) {
                pairs.push_back(boys[x]);
                x+=1;
            } else {
                pairs.push_back(girls[y]);
                y+=1;
            }
    }
    return pairs;
}

int main(int argc, char* args[]){
    std::vector<std::string> girls = {"Eve","Ashley","Claire","Kat","Jane"};
    std::vector<std::string> boys = {"Joe","Fred","Tom","Todd","Neef","Jeff"};



    // Write a method that joins the two lists by matching one girl with one boy into a new list
    // If someone has no pair, he/she should be the element of the list too
    // Exepected output: "Eve", "Joe", "Ashley", "Fred"...

    std::vector<std::string> matches =  makingMatches(girls, boys);

    for(int i = 0; i < matches.size(); ++i) {
        std::cout << matches[i] << " ";
    }

    return 0;
}