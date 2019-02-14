//
// Created by Borbáls on 2019. 02. 07..
//

#ifndef TESTINGTESTER_MYCLASS_H
#define TESTINGTESTER_MYCLASS_H

#include <vector>

class Sum {
public:
    Sum();
    void addInt(int x);
    int sum(std::vector<int> integersToSum);
private:
    std::vector<int> integersToSum;
};


#endif //TESTINGTESTER_MYCLASS_H
