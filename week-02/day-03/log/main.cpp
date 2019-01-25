#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

int main() {

    std::vector<std::string> allinput;
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
        allinput.push_back(day);
        allinput.push_back(month);
        allinput.push_back(date);
        allinput.push_back(time);
        allinput.push_back(year);
        urls.push_back(url);
        getPost.push_back(getpost);
        }

    dataset.close();

    std::string uniqueIP[urls.size()];
    for(int i=0; i<urls.size(); i++){
        uniqueIP[i]=urls[i];
        std::cout << uniqueIP[i] << std::endl;
    }

    float g=0;
    float p=0;
    for (int i =0; i<getPost.size(); i++){
    if(getPost[i]=="POST"){
     g+=1;
    }else{
     p+=1;
    }
}
    std::cout << "Ratio of gets out of all requests: " << g/getPost.size() << " Ratio of posts out of all requests: " << p/getPost.size();

    return 0;
}