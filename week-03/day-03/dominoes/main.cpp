#include <iostream>
#include <vector>

#include "Dominoes.h"

std::vector<Dominoes> initializeDominoes()
{
    std::vector<Dominoes> dominoes;
    dominoes.push_back(Dominoes(5, 2));
    dominoes.push_back(Dominoes(4, 3));
    dominoes.push_back(Dominoes(1, 5));
    dominoes.push_back(Dominoes(3, 7));
    dominoes.push_back(Dominoes(2, 4));
    dominoes.push_back(Dominoes(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Dominoes> dominoes = initializeDominoes();

    std::vector<Dominoes> dominoesInOrder;
    dominoesInOrder.push_back(dominoes[0]);

    int x=0;

    while(dominoesInOrder.size()!=dominoes.size()) {
        for (int i = 1; i <= dominoes.size(); i++) {
            if (dominoesInOrder[x].getValues().second == dominoes[i].getValues().first) {
                dominoesInOrder.push_back(dominoes[i]);
                x++;
            }
        }
    }

    for(int i=0; i<dominoesInOrder.size(); i++){
        std::cout << dominoesInOrder[i].getValues().first << " " << dominoesInOrder[i].getValues().second << " ";
    }

    return 0;
}