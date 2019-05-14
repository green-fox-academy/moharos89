#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char *word , char letter);

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";
    char letter = 'g';

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d\n" , count_between_chars(word , letter));

    return 0;
}

int count_between_chars(char *word , char letter)
{
    char *first = NULL;
    char *second = NULL;
    for (int i = 0; i < strlen(word); ++i) {
        if (letter == word[i] && first == NULL){
            first = &word[i];
        } else if (letter == word[i]){
            second = &word[i];
        }
    }
    return second - first - 1;

}