//
// Created by Bence on 2019.04.23..
//

#ifndef GREENFOXINHERITANCE_PERSON_H
#define GREENFOXINHERITANCE_PERSON_H

#include <iostream>
#include <string>
#include <vector>

enum Gender {
    MALE,
    FEMALE,
    Other
};

class Person {
public:
    Person();

    Person(std::string name, int age, Gender gender);

    void setName(std::string name);

    void setAge(int age);

    void setGender(Gender gender);

    const std::string getName() const;

    const int getAge() const;

    const Gender getGender() const;

    virtual void introduce() const;

    virtual void getGoal() const;

    const std::string genderReturner() const;

protected:
    std::string _name;
    int _age;
    Gender _gender;


};


#endif //GREENFOXINHERITANCE_PERSON_H
