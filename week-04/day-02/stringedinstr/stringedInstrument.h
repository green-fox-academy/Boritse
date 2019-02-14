//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef STRINGEDINSTR_STRINGEDINSTRUMENT_H
#define STRINGEDINSTR_STRINGEDINSTRUMENT_H

#include "instrument.h"

class StringedInstrument {
public:
    StringedInstrument(int _numberOfStrings);
    virtual void sound()=0;
    void play(Instrument _instrument);
protected:
    int numberOfStrings;
};


#endif //STRINGEDINSTR_STRINGEDINSTRUMENT_H
