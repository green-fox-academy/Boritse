//
// Created by Borbáls on 2019. 01. 30..
//

#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H

#include "sharpie.h"
#include <string>
#include <vector>

class sharpieSet {

public:
    sharpieSet();
    int countUsuable();
    void fillMyVect();
    void removeTrash();
    void useSharpie(int i);

private:

    sharpie black = sharpie("black", 1.2);
    sharpie blue = sharpie("blue", 1.7);
    sharpie pink = sharpie("pink", 1.3);
    sharpie green = sharpie("green", 1.2);
    sharpie purple = sharpie("purple", 1.1);

    std::vector<sharpie> sharpvect;
};


#endif //SHARPIESET_SHARPIESET_H
