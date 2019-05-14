#include <stdio.h>

int main()
{
    printf("Hello, Bence!\n");

    // Greet 3 of your classmates with this program, in three separate lines
    // like:
    //
    // Hello, Esther!
    // Hello, Mary!
    // Hello, Joe!

    printf("Hello, Joe!\n");
    printf("Hello, Jesse!\n");
    printf("Hello, Rebeca!\n");

    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87
    char name[] = "Bence Moharos";
    int age = 30;
    float height = 1.72;
    printf("%s\n" , name);
    printf("%d\n" , age);
    printf("%.2f\n" , height);



    return 0;
}