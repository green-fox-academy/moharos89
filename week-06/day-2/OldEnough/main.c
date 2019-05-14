#include <stdio.h>

int oldEnough(int number);

int main()
{
    int number = 0;
    puts("How old are you?");
    scanf("%d", &number);
    oldEnough(number);

    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    printf("Hello, World!\n");
    return 0;
}

int oldEnough(int number)
{
    if ( number >= 18) {
        return 1;
    } else {
        return 0;
    }
}