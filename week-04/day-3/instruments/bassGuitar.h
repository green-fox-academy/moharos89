//
// Created by Bence on 2019.04.24..
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H


#include "stringedInstrument.h"

class BassGuitar: public StringedInstrument {
public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    void setName(std::string);
    const std::string getName() const;
    void setSound(std::string sound);

    void play() override;

    std::string sound() override;


private:
    std::string _sound;

};


#endif //INSTRUMENTS_BASSGUITAR_H
