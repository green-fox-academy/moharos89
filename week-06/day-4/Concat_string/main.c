#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concat(char word1[] , char word2[]);

int main()
{
    char *newWord = concat("App" , "le");
    printf("%s\n" , newWord);

    free(newWord);
    newWord = NULL;
    
    return 0;
}

char *concat(char word1[] , char word2[])
{
    char *wordPtr = (char *) malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));
    for (int i = 0; i < strlen(word1); ++i) {
        wordPtr[i] = word1[i];
        wordPtr[i + 1] = 0;
    }
    for (int i = 0; i < strlen(word2); ++i) {
        wordPtr[strlen(word1) + i] = word2[i];
        wordPtr[strlen(word1) + i + 1] = 0;
    }
    return wordPtr;
}