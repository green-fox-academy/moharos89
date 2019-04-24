//
// Created by Bence on 2019.04.24..
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H


#include "instrument.h"

class StringedInstrument : public Instrument {
public:
    StringedInstrument();

    StringedInstrument(int numberOfStrings);

    void setNumberOfStrings(int numberOFStrings);

    const int getNumberOFStrings() const;

    virtual std::string sound() = 0;

    std::string printNumberOfStrings();

protected:

private:
    int _numberOfStrings;



};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
