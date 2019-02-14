//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef STRINGEDINSTR_INSTRUMENT_H
#define STRINGEDINSTR_INSTRUMENT_H

#include <string>


class Instrument {
public:
    Instrument(std::string _name);
    virtual void play()=0;
protected:
    std::string name;
};


#endif //STRINGEDINSTR_INSTRUMENT_H
