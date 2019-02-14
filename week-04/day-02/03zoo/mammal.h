//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_03ZOO_MAMMAL_H
#define INC_03ZOO_MAMMAL_H

#include "animal.h"

class Mammal : public Animal {
public:
    Mammal(std::string _name);
    std::string getName() override;
    std::string breed() override;
protected:

};


#endif //INC_03ZOO_MAMMAL_H
