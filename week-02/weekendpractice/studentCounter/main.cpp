#include <iostream>
#include <string>
#include <vector>
#include <utility> //for std::pair
#include <map>

std::vector<std::string> getChildrenWithMoreThanFourCandies(const std::vector<std::pair<std::string, std::map<std::string, int>>>& students)
{
    //  - The names of students who have more than 4 candies
    std::vector<std::string> hasManyCandies;

    for(int i=0; i<students.size(); i++){
        for (std::map<std::string, int>::const_iterator it = students[i].second.begin(); it != students[i].second.end(); ++it) {
            if (it -> first=="candies" && it -> second > 4){
                hasManyCandies.push_back(students[i].first);
                }
        }
    }
    return hasManyCandies;
}

int sumOfAgeWithLessThanFiveCandies(const std::vector<std::pair<std::string, std::map<std::string, int>>>& students)
{
    std::vector<int> ageContainer;
    int sumOfAge=0;

    for(int i=0; i<students.size(); i++){
        for(std::map<std::string, int>::const_iterator it = students[i].second.begin(); it != students[i].second.end(); ++it){
            if(it -> first=="candies" && it -> second <5){
                for(std::map<std::string, int>::const_iterator it = students[i].second.begin(); it != students[i].second.end(); ++it){
                    if(it -> first=="age"){
                        sumOfAge+=it ->second;
                    }
                }
            }
        }
    }
    return sumOfAge;
}

int main(int argc, char* args[])
{
    std::vector<std::pair<std::string, std::map<std::string, int>>> students;

    std::map<std::string, int> TheodorData;
    TheodorData.insert(std::make_pair("age", 9));
    TheodorData.insert(std::make_pair("candies", 2));
    students.push_back(std::make_pair("Theodor", TheodorData));

    std::map<std::string, int> PaulData;
    PaulData.insert(std::make_pair("age", 10));
    PaulData.insert(std::make_pair("candies", 1));
    students.push_back(std::make_pair("Paul", PaulData));

    std::map<std::string, int> MarkData;
    MarkData.insert(std::make_pair("age", 7));
    MarkData.insert(std::make_pair("candies", 3));
    students.push_back(std::make_pair("Mark", MarkData));

    std::map<std::string, int> PeterData;
    PeterData.insert(std::make_pair("age", 12));
    PeterData.insert(std::make_pair("candies", 5));
    students.push_back(std::make_pair("Peter", PeterData));

    std::map<std::string, int> OlafData;
    OlafData.insert(std::make_pair("age", 12));
    OlafData.insert(std::make_pair("candies", 7));
    students.push_back(std::make_pair("Olaf", OlafData));

    std::map<std::string, int> GeorgeData;
    GeorgeData.insert(std::make_pair("age", 3));
    GeorgeData.insert(std::make_pair("candies", 2));
    students.push_back(std::make_pair("George", GeorgeData));



    std::cout << "Children with more than 4 candies: ";

    std::vector<std::string> childrenWithManyCandies = getChildrenWithMoreThanFourCandies(students);

    for(int i = 0; i < childrenWithManyCandies.size(); ++i) {
        std::cout << childrenWithManyCandies[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Sum of those who have less than 5 candies: " << sumOfAgeWithLessThanFiveCandies(students) << std::endl;

    return 0;
}