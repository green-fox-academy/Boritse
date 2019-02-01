#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int numberOfMembers;
    std::vector<int> memberVector;
    std::cout << "How many members should the suicidal group have?" << std::endl;
    std::cin >> numberOfMembers;

    for(int i=1; i<=numberOfMembers; i++){
        memberVector.push_back(i);
    }

    for(int i=2; i<3; i++) {
        memberVector.erase(std::remove_if(begin(memberVector), end(memberVector), i % 2 == 0), end(memberVector));
    }

    while(memberVector.size()>1) {
        for (int i = 0; i < memberVector.size(); i++) {
            if (memberVector.size() / 2 == 0) {
                memberVector.erase(std::remove_if(begin(memberVector), end(memberVector), i%2==0),
                                   end(memberVector));
            } else {
                memberVector.erase(std::remove_if(begin(memberVector), end(memberVector), i%2!=0),
                                   end(memberVector));
            }
        }
    }
    std::cout << "The number of the winning seat is: " << memberVector[0];
    return 0;
}