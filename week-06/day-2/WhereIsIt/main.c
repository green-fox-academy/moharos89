#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int finder(char word[] , char character);

int main()
{
    printf("Write a word and a character!\n");
    char word[20];
    char character;
    scanf("%s\n" , &word);
    scanf("%c" , &character);
    printf("%d\n" , finder(word , character));

    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    return 0;
}

int finder(char word[] , char character)
{
    for (int i = 0; i < strlen(word) ; ++i) {
        if(character == word[i]) {
            return i;
        }
    }
    return -1;
}