//
// Created by Bence on 2019.04.23..
//

#ifndef GREENFOXINHERITANCE_COHORT_H
#define GREENFOXINHERITANCE_COHORT_H

#include "Student.h"
#include "Mentor.h"

class Cohort {
public:
    Cohort(std::string name);
    void addStudent(Student*);
    void addMentor(Mentor*);
    void setName(std::string name);
    void info();
private:
    std::string _name;
    std::vector<Student> _students;
    std::vector<Mentor> _mentors;


};


#endif //GREENFOXINHERITANCE_COHORT_H
