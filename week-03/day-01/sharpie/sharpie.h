//
// Created by Borbáls on 2019. 01. 29..
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <string>

class sharpie {
public:
    sharpie(std::string colour, float width);
    float use();
private:
    std::string colour;
    float width;
    float inkAmount;

};


#endif //SHARPIE_SHARPIE_H
