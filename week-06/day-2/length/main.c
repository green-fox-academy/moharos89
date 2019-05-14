#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLenght(char *name);
int stringLenght2(char *name);


int main()
{
    printf("What is your name?\n");
    char *name;
    scanf("%s" , name);
    printf("%d\n" , stringLenght(name));
    printf("%d\n" , stringLenght2(name));

    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    return 0;
}

int stringLenght(char *name)
{
    return strlen(name);
}

int stringLenght2(char *name)
{
    int counter = 0;
    while (*(name++) != NULL) {
        counter++;
    }
    return counter;
}