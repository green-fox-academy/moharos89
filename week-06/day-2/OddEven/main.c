#include <stdio.h>
#include <stdlib.h>

int isEven(int *number);

int main()
{
    puts("Write down a number!");
    int a;
    scanf("%d" , &a);
    printf("%d\n" , isEven(&a));

    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    return 0;
}

int isEven(int *number)
{
    if(*number % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}