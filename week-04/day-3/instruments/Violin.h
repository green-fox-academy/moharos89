//
// Created by Bence on 2019.04.24..
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H


#include "stringedInstrument.h"

class Violin : public StringedInstrument {
public:
    Violin();
    Violin(int numberOfStrings);
    void setName(std::string name);
    const std::string getName() const;
    void setSound(std::string sound);

    void play() override;

    std::string sound() override;

private:
    std::string _sound;

};


#endif //INSTRUMENTS_VIOLIN_H
