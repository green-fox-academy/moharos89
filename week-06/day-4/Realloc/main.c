#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int sum(int *arrayPtr , int number);
void arrayFiller(int *arrayPtr, int number);
void arrayPrinter(int *arrayPtr, int number);

int main()
{
    puts("Write down a number!");
    int number;
    scanf("%d" , &number);
    int *arrayPtr = (int *) malloc(number * sizeof(int));
    for (int i = 0; i < number; ++i) {
        printf("Give me a number!\n");
        scanf("%d" , &arrayPtr[i]);
    }

    int newNumber = sum(arrayPtr , number);
    arrayPtr = realloc(arrayPtr ,  newNumber * sizeof(int));
    arrayFiller(arrayPtr , newNumber);
    arrayPrinter(arrayPtr, newNumber);
    free(arrayPtr);
    arrayPtr = NULL;

    return 0;
}

int sum(int *arrayPtr , int number)
{
    int sum = 0;
    for (int i = 0; i < number; ++i) {
        sum += arrayPtr[i];
    }
    return sum;
}

void arrayFiller(int *arrayPtr, int number)
{
    for (int i = 0; i < number; ++i) {
        arrayPtr[i] = i + 1;
    }
}

void arrayPrinter(int *arrayPtr, int number)
{
    for (int i = 0; i < number; ++i) {
        printf("%d\n" , arrayPtr[i]);

    }
}