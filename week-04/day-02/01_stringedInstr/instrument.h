//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef INC_01_STRINGEDINSTR_INSTRUMENT_H
#define INC_01_STRINGEDINSTR_INSTRUMENT_H

#include <string>

class Instrument {
public:
    Instrument(std::string _name);
    virtual void play()=0;
protected:
    std::string name;
};


#endif //INC_01_STRINGEDINSTR_INSTRUMENT_H
