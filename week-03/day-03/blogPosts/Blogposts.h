//
// Created by Borbáls on 2019. 02. 01..
//

#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H

#include <string>

class Blogpsts {
public:
    Blogpsts(std::string, std::string, std::string, std::string);
private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string date;
};


#endif //BLOGPOST_BLOGPOST_H