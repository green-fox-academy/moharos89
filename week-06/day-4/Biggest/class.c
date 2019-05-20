//
// Created by Bence on 2019.05.16..
//

#include "class.h"

int askHowManyClass()
{
    int numberOfClass;
    puts("How many class did the exam?");
    scanf("%d", &numberOfClass);
    return numberOfClass;
}

int askHowManyStudent()
{
    int numberOfStudent;
    puts("How many student did the exam?");
    scanf("%d", &numberOfStudent);
    return numberOfStudent;
}

int *askresult(int howManyStudent)
{
    int *percantages = (int *) malloc(howManyStudent * sizeof(int));
    for (int j = 0; j < howManyStudent; ++j) {
        puts("Write down the percentages!");
        scanf("%d", &percantages[j]);
    }
    return percantages;
}

class_t *getExam(int numberOfClass);

char *setName()
{
    char *name = (char *) calloc(10, sizeof(char));
    puts("Write down the name of the class");
    scanf("%s", name);
    int exactName = strlen(name);
    name = (char *) realloc(name, (exactName + 1) * sizeof(char));
    return name;
}

void setPercentage(class_t *class, int percentage, int number);