//
// Created by Bence on 2019.04.23..
//

#include "Student.h"

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) : Person(name, age,
                                                                                                      gender) {
    setPreviousOrganization(previousOrganization);
    setSkippedDays(0);
}

Student::Student() : Person() {
    setPreviousOrganization("The School of Life");
    setSkippedDays(0);

}

void Student::introduce() const {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderReturner() << " from "
              << _previousOrganization << " who skipped " << _skippedDays << " days from the course already."
              << std::endl;
}

void Student::getGoal() const {
    std::cout << "My goal: Is be a junior software developer" << std::endl;
}

void Student::setSkippedDays(int skippedDays) {
    _skippedDays = skippedDays;

}

void Student::skipDays(int numberOfDays) {
    _skippedDays += numberOfDays;

}

const int Student::getSkippedDays() const {
    return _skippedDays;
}

const std::string Student::getPreviousOrganization() const {
    return _previousOrganization;
}

void Student::setPreviousOrganization(std::string previousOrganization) {
    _previousOrganization = previousOrganization;

}
