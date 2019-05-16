#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *multiString(char word[] , int number);

int main()
{
    char *newWord = multiString("Apple" , 6);
    printf("%s\n" , newWord);
    free(newWord);
    newWord = NULL;

    return 0;
}

char *multiString(char word[] , int number)
{
    char *multiWord = (char *) calloc((strlen(word) * number + 1) , sizeof(char));
    for (int i = 0; i < number; ++i) {
        strcat(multiWord , word);
    }
    return multiWord;

}