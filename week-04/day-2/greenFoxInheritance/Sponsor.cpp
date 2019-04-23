//
// Created by Bence on 2019.04.23..
//

#include "Sponsor.h"

Sponsor::Sponsor() : Person() {
    setCompany("Google");
    setHiredStudents(0);

}

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) : Person(name, age, gender) {
    setCompany(company);
    setHiredStudents(0);

}

void Sponsor::setCompany(std::string company) {
    _company = company;

}

void Sponsor::setHiredStudents(int hiredStudents) {
    _hiredStudents = hiredStudents;

}

void Sponsor::introduce() const {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderReturner() << " who represents "
              << _company << " and hired " << _hiredStudents << " students so far" << std::endl;
}

void Sponsor::getGoal() const {
    std::cout << "My goal is: Hire brilliant junior softwars developers." << std::endl;
}

void Sponsor::hire() {
    _hiredStudents += 1;

}
