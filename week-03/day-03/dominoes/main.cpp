#include <iostream>
#include <vector>

#include "Dominoes.h"

std::vector<Dominoes> initializeDominoes()
{
    std::vector<Dominoes> dominoes;
    dominoes.push_back(Dominoes(5, 2));
    dominoes.push_back(Dominoes(4, 6));
    dominoes.push_back(Dominoes(1, 5));
    dominoes.push_back(Dominoes(6, 7));
    dominoes.push_back(Dominoes(2, 4));
    dominoes.push_back(Dominoes(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Dominoes> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    return 0;
}