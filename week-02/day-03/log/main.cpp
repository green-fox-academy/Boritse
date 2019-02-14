#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

float getpostRatio(std::vector<std::string> getsPosts)
{
    float g=0;
    float p=0;
    for (int i =0; i<getsPosts.size(); i++){
        if(getsPosts[i]=="POST"){
        g+=1;
        }else{
        p+=1;
        }
    }
    return g/p;
}

void uniquizer(std::vector<std::string> &duplicatesPresent)
{
    std::sort(duplicatesPresent.begin(), duplicatesPresent.end());
    duplicatesPresent.erase(std::unique(duplicatesPresent.begin(), duplicatesPresent.end()), duplicatesPresent.end());
}

int main() {

    std::vector<std::string> urls;
    std::vector<std::string> getPost;
    std::string day;
    std::string month;
    std::string date;
    std::string time;
    std::string year;
    std::string url;
    std::string getpost;
    std::string slash;

    std::ifstream dataset("log.txt");

    while(dataset >> day >> month >> date >> time >> year >> url >> getpost >> slash){

        urls.push_back(url);
        getPost.push_back(getpost);
        }

    dataset.close();

    std::cout << "Number of IP-s before uniquizing: " << urls.size() << std::endl;
    uniquizer(urls);
    std::cout << "Number of IP-s after uniquizing: " << urls.size() << std::endl;

    std::cout << "The get/post request ratio was: " << getpostRatio(getPost) << ".";

    return 0;
}