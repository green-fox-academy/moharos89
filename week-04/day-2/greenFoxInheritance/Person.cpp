//
// Created by Bence on 2019.04.23..
//

#include "Person.h"

Person::Person() {
    setName("Jane Doe");
    setAge(30);
    setGender(FEMALE);

}

Person::Person(std::string name, int age, Gender gender) {
    setName(name);
    setAge(age);
    setGender(gender);

}

void Person::setName(std::string name) {
    _name = name;

}

void Person::setAge(int age) {
    _age = age;
}

void Person::setGender(Gender gender) {
    _gender = gender;
}

const std::string Person::getName() const {
    return _name;
}

const int Person::getAge() const {
    return _age;
}

const Gender Person::getGender() const {
    return _gender;
}

void Person::introduce() const {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderReturner() << std::endl;
}

void Person::getGoal() const{
    std::cout << "My goal is : Live for the moment" << std::endl;
}

const std::string Person::genderReturner() const{
    switch (_gender) {
        case MALE:
            return "male";
        case FEMALE:
            return "female";
        case Other:
            return "other";
    }


}
