//
// Created by Bence on 2019.04.17..
//
#include <iostream>
#include <string>

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int number);
    void setNumber(int number);
    void setNumberbackup(int numberbackup);
    int get();
    int getNumberbackup();
    void add(int number);
    void add();
    void reset();

private:
    int _number;
    int _numberbackup;


};


#endif //COUNTER_COUNTER_H
