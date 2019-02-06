//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_04MODELDEV_PRINTER3D_H
#define INC_04MODELDEV_PRINTER3D_H

#include <string>
#include "printer.h"

class Printer3D : public Printer {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize() override;
protected:
    int _sizeX;
    int _sizeY;
    int _sizeZ;
};


#endif //INC_04MODELDEV_PRINTER3D_H
