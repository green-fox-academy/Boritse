//
// Created by Borbáls on 2019. 02. 06..
//

#include "stringedInstrument.h"

StringedInstrument::StringedInstrument(std::string _name, int _numberOfStrings, std::string _uniqueSound) : Instrument(_name){}

void StringedInstrument::play() {
    sound();
}