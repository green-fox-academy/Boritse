//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_01_STRINGEDINSTR_ELECTRICGUITAR_H
#define INC_01_STRINGEDINSTR_ELECTRICGUITAR_H

#include "stringedInstrument.h"
#include <string>

class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar(int _numberOfStrings, std::string _uniqueSound);
    void sound() override;
};


#endif //INC_01_STRINGEDINSTR_ELECTRICGUITAR_H
