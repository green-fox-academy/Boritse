//
// Created by Borbáls on 2019. 02. 01..
//

#include "Dominoes.h"

Dominoes::Dominoes(int valueA, int valueB)
{
    _values = std::make_pair(valueA, valueB);
}

std::pair<int,int> Dominoes::getValues()
{
    return _values;
}

std::string Dominoes::toString()
{
    return "[" + std::to_string(_values.first) + ", " + std::to_string(_values.second) + "]";
}


