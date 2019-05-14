#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *appendA(char word[]);

int main()
{
    printf("Write a word!\n");
    char word[20];
    scanf("%s" , word);
    printf("%s\n" , appendA(word));

    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    return 0;
}

char *appendA(char word[])
{
    char *newWord = strcat(word , "a");
    return newWord;
}