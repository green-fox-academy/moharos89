#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main ()
{
    puts("What is your name and how old are you?");
    char array[50];
    gets(array);
    char *first_name = strtok(array , " ");
    char *last_name = strtok(NULL , " ");
    char *agePtr = strtok(NULL , " ");
    int age = atoi(agePtr);

    printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

    return 0;
}