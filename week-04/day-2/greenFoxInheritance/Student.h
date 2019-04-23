//
// Created by Bence on 2019.04.23..
//

#ifndef GREENFOXINHERITANCE_STUDENT_H
#define GREENFOXINHERITANCE_STUDENT_H

#include "Person.h"

class Student : public Person{
public:
    Student(std::string name , int age , Gender gender , std::string previousOrganization);
    Student();
    void introduce() const override;
    void getGoal() const override;
    void setSkippedDays(int skippedDays);
    void skipDays(int numberOfDays);
    const int getSkippedDays() const;
    void setPreviousOrganization(std::string previousOrganization);
    const std::string getPreviousOrganization() const;



private:
    std::string _previousOrganization;
    int _skippedDays;

};


#endif //GREENFOXINHERITANCE_STUDENT_H
