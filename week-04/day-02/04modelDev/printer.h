//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_04MODELDEV_PRINTER_H
#define INC_04MODELDEV_PRINTER_H


class Printer {
public:
    Printer();
    virtual std::string getSize()=0;
    std::string print();
};


#endif //INC_04MODELDEV_PRINTER_H
