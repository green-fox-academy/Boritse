//
// Created by Borbáls on 2019. 01. 29..
//

#include <string>

#ifndef INC_01_POSTIT_POSTIT_H
#define INC_01_POSTIT_POSTIT_H


class postit {
public:
    postit(std::string backgroundColour, std::string textItself, std::string textColour);
private:
    std::string backgroundColour;
    std::string textItself;
    std::string textColour;

};


#endif //INC_01_POSTIT_POSTIT_H
