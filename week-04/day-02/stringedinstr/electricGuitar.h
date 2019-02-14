//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef STRINGEDINSTR_ELECTRICGUITAR_H
#define STRINGEDINSTR_ELECTRICGUITAR_H

#include "stringedInstrument.h"
#include <string>

class ElectricGuitar : public StringedInstrument{
public:
    ElectricGuitar();
    void sound();
private:
    std::string soundInst="Twang";
};


#endif //STRINGEDINSTR_ELECTRICGUITAR_H
