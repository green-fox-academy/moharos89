//
// Created by Bence on 2019.04.23..
//

#ifndef GREENFOXINHERITANCE_MENTOR_H
#define GREENFOXINHERITANCE_MENTOR_H

#include "Person.h"

enum Level {
    JUNIOR ,
    INTERMEDIATE ,
    SENIOR
};

class Mentor : public Person {
public:
    Mentor();
    Mentor(std::string name , int age , Gender gender , Level level);
    void setLevel(Level level);
    void getGoal() const override;
    void introduce() const override;
    const std::string getLevel() const;
private:
    Level _level;

};


#endif //GREENFOXINHERITANCE_MENTOR_H
