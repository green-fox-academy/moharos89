#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char *word, char *sentence);

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "apple";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 1
    printf("%d\n" , is_in_sentence(word, sentence));

    return 0;
}

int is_in_sentence(char *word, char *sentence)
{
    int length = strlen(sentence);
    char newSentence[length];
    for (int i = 0; i <= length; ++i) {
        if (sentence[i] >= 65 && sentence[i] <= 92) {
            newSentence[i] = sentence[i] + 32;
        } else {
            newSentence[i] = sentence[i];
        }
    }
    int countBegin = 0;
    int countEnd = 0;
    for (int j = 0; j < length; ++j) {
        if (newSentence[j] == ' ' || newSentence[j] == '.'){
            countEnd = j;
            char temp[countEnd - countBegin];
            for (int i = 0; i < countEnd - countBegin; ++i) {
                temp[i] = newSentence[countBegin + i];
            }
            temp[countEnd - countBegin] = 0;
            countBegin = countEnd + 1;
            if (strcmp(temp , word) == 0){
                return 1;
            }
        }
    }
    return 0;
}