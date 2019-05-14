#include <stdio.h>

int main()
{
    float a;
    float b;
    float c;

    printf("Write down the three side of a cuboid:\n");
    scanf("%f" , &a);
    scanf("%f" , &b);
    scanf("%f" , &c);
    float volume = a * b * c;
    float surface = 2 * (a * b + a * c + b * c);
    printf("Surface Area: %.0f\n" , surface);
    printf("Volume: %.0f\n" , volume);

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    printf("Hello, World!\n");
    return 0;
}