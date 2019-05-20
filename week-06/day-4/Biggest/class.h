//
// Created by Bence on 2019.05.16..
//

#ifndef BIGGEST_CLASS_H
#define BIGGEST_CLASS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *_name;
    int *_percentage;
    int _howManyStudent;

} class_t;

int askHowManyClass();

int askHowManyStudent();

int *askresult(int howManyStudent);

class_t *setExam(int numberOfClass);

char *setName();

void setPercentage(class_t *class, int percentage, int number);


#endif //BIGGEST_CLASS_H
