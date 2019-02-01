//
// Created by Borbáls on 2019. 01. 30..
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <string>


class sharpie {
public:
    sharpie(std::string _colour, float _width);
    float use();
    int currentInk();
private:
    std::string colour;
    float width;
    float inkAmount;
};


#endif //SHARPIE_SHARPIE_H
