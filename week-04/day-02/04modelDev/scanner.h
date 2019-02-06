//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_04MODELDEV_SCANNER_H
#define INC_04MODELDEV_SCANNER_H

#include <string>

class Scanner {
public:
    Scanner(int speed);
    std::string scan();
protected:
    int _speed;
};


#endif //INC_04MODELDEV_SCANNER_H
