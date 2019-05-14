#include <stdio.h>
#include <stdlib.h>

int isEqual(int *num1, int *num2);

int main()
{
    int num1 = 0;
    int num2 = 0;
    printf("Write two number!\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("%d\n", isEqual(&num1, &num2));


    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    return 0;
}

int isEqual(int *num1, int *num2)
{
    if (*num1 == *num2) {
        return 1;
    } else {
        return 0;
    }
}