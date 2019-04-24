//
// Created by Bence on 2019.04.24..
//

#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <string>
#include <vector>
#include <iostream>

enum Gender {
    MALE,
    FEMALE
};

class Animal {
public:
    Animal();

    void setName(std::string name);

    void setAge(int age);

    void setGender(Gender gender);

    void setHunger(int hunger);

    void setThirst(int thirst);

    void eat(int amount);

    void drink(int amount);

    const std::string getGender(Gender gender) const;

    const int getAge() const;

    virtual const std::string getName() const = 0;

    virtual std::string breed() = 0;


protected:
    std::string _name;

private:
    int _age;
    Gender _gender;
    int _hunger;
    int _thirst;

};


#endif //ZOO_ANIMAL_H
