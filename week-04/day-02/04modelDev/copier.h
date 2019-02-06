//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_04MODELDEV_COPIER_H
#define INC_04MODELDEV_COPIER_H

#include "scanner.h"
#include "printer2D.h"
#include "printer.h"

class Copier : public Scanner, public Printer2D {
public:
    Copier(int sizeX, int sizeY, int speed);
    std::string copy();
};


#endif //INC_04MODELDEV_COPIER_H

