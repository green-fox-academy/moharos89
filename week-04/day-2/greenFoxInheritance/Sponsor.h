//
// Created by Bence on 2019.04.23..
//

#ifndef GREENFOXINHERITANCE_SPONSOR_H
#define GREENFOXINHERITANCE_SPONSOR_H

#include "Person.h"

class Sponsor : public Person {
public:
    Sponsor();
    Sponsor(std::string name , int age , Gender gender , std::string company);
    void setCompany(std::string company);
    void setHiredStudents(int hiredStudents);
    void introduce() const override;
    void getGoal() const override;
    void hire();

private:
    std::string _company;
    int _hiredStudents;

};


#endif //GREENFOXINHERITANCE_SPONSOR_H
