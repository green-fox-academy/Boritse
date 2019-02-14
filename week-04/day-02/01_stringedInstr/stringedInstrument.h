//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_01_STRINGEDINSTR_STRINGEDINSTRUMENT_H
#define INC_01_STRINGEDINSTR_STRINGEDINSTRUMENT_H

#include "instrument.h"

class StringedInstrument : public Instrument{
public:
    StringedInstrument(std::string _name, int _numberOfStrings, std::string _uniqueSound);
    virtual void sound() = 0;
    void play() override;
protected:
    int numberOfStrings;
    std::string uniqueSound;
};


#endif //INC_01_STRINGEDINSTR_STRINGEDINSTRUMENT_H
