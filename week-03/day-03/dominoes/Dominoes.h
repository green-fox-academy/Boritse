//
// Created by Borbáls on 2019. 02. 01..
//

#ifndef DOMINOES_DOMINOES_H
#define DOMINOES_DOMINOES_H

#include <iostream>
#include <utility>

class Dominoes
{
public:
    Dominoes(int valueA, int valueB);

    std::pair<int,int> getValues();
    std::string toString();

private:
    std::pair<int,int> _values;
};


#endif //DOMINOES_DOMINO_H#endif //DOMINOES_DOMINOES_H
