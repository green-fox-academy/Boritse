//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_04MODELDEV_PRINTER2D_H
#define INC_04MODELDEV_PRINTER2D_H

#include <string>
#include "printer.h"

class Printer2D : public Printer{
public:
    Printer2D(int sizeX, int sizeY);
    std::string getSize() override;
protected:
    int _sizeX;
    int _sizeY;
};


#endif //INC_04MODELDEV_PRINTER2D_H
