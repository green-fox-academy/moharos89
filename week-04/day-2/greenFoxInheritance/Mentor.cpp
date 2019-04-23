//
// Created by Bence on 2019.04.23..
//

#include "Mentor.h"

Mentor::Mentor() : Person() {
    setLevel(INTERMEDIATE);

}

Mentor::Mentor(std::string name, int age, Gender gender, Level level) : Person(name, age, gender) {
    setLevel(level);
}

void Mentor::setLevel(Level level) {
    _level = level;
}

void Mentor::getGoal() const {
    std::cout << "My goal is: Educate billiant junior software developers" << std::endl;
}

void Mentor::introduce() const {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderReturner() << " " << getLevel() << " mentor"
              << std::endl;
}

const std::string Mentor::getLevel() const {
    switch (_level) {
        case JUNIOR:
            return "junior";
        case INTERMEDIATE:
            return "intermediate";
        case SENIOR:
            return "senior";
    }
}
