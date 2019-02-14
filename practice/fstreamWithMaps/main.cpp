#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ifstream workingFile("data.txt");
    /*if(!workingFile.is_open())
        throw "file could not be opened"; */
    std::string name;
    std::string type;
    std::string date;
//    std::map<std::string int> usageData;
    std::vector<std::string> allEntries;
    while(workingFile >> name >> type >> date){
        //usageData[type]++;
        allEntries.push_back(type);
    }
    workingFile.close();
    std::vector<std::string> uniqueHumans=allEntries;

    sort( uniqueHumans.begin(), uniqueHumans.end() );
    uniqueHumans.erase( unique( uniqueHumans.begin(), uniqueHumans.end() ), uniqueHumans.end() );

    std::vector<std::pair<std::string, int>> solution;

    for(int i=0; i<uniqueHumans.size(); i++) {
        int counter=0;
        for (int j = 0; j < allEntries.size(); j++) {
            if (uniqueHumans[i] == allEntries[j]) {
                counter++;
            }
        }
        solution.push_back(make_pair(uniqueHumans[i], counter));
    }

    std::ofstream pureData("pureData.txt");
    for(int i=0; i<solution.size(); i++){
        pureData << solution[i].first << ": " << solution[i].second << std::endl;
    }

    pureData.close();
    return 0;
}