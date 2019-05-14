#include <stdio.h>
#include <time.h>


int main()
{
    int number = 9;
    printf("Guess the number!\n");
    int guessed = 0;
    scanf("%d" , &guessed);

    if (number != guessed) {
        while (number != guessed) {
            if(guessed > number) {
                printf("The stored number is lower\n");
                scanf("%d" , &guessed);

            } else {
                printf("The stored number is higher\n");
                scanf("%d" , &guessed);
            }
        }
        printf("You found the number: %d\n" , number);
    } else {
        printf("You found the number: %d\n" , number);
    }
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8
    printf("Hello, World!\n");
    return 0;
}