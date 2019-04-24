//
// Created by Bence on 2019.04.24..
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H


#include "stringedInstrument.h"

class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar();
    ElectricGuitar(int numberOfStrings);

    void setName(std::string name);


    void play() override;

    void setSound(std::string sound);

    std::string sound() override;

protected:

private:
    std::string _sound;

};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
