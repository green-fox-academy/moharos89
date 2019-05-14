#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int same(char string1[] , char string2[]);

int main()
{
    printf("Write two words!\n");
    char string1[20];
    char string2[20];
    scanf("%s" , string1);
    scanf("%s" , string2);
    printf("%d\n" , same(string1 , string2));
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    return 0;
}
int same(char string1[] , char string2[])
{
    if (strcmp(string1 , string2) == 0) {
        return 1;
    } else {
        return 0;
    }
}