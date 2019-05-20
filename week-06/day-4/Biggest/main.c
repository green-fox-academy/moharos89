#include <stdio.h>
#include <stdlib.h>
#include "class.h"

int main()
{
    int howManyClass = askHowManyClass();
    class_t *pointers[howManyClass];
    for (int i = 0; i < howManyClass; ++i) {
        int howManyStudent = askHowManyStudent();
        char *namePtr = setName();
        int *percentages = askresult(howManyStudent);
        class_t *tempClass = (class_t *) malloc(sizeof(class_t));
        tempClass->_name = namePtr;
        tempClass->_percentage = percentages;
        tempClass->_howManyStudent = howManyStudent;
        pointers[i] = tempClass;
    }
    for (int l = 0; l < howManyClass; ++l) {
        printf("%s\n", pointers[l]->_name);
        for (int j = 0; j < pointers[l]->_howManyStudent; ++j) {
            printf("%d\n", pointers[l]->_percentage[j]);
        }
    }
    for (int l = 0; l < howManyClass; ++l) {
        free(pointers[l]->_name);
        free(pointers[l]->_percentage);
        free(pointers[l]);
    }

    return 0;
}