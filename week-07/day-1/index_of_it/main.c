#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char *word, const char *sentence);

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char* word = "doctor";
    const char* sentence = "An apple a day keeps the doctor away.";

    // the output should be: 6
    printf("%d" , is_in_sentence(word, sentence));

    return 0;
}

int is_in_sentence(char *word, const char *sentence)
{
    int lenght = strlen(sentence);
    char newSentence[lenght];
    for (int i = 0; i < lenght; ++i) {
        if(sentence[i] >= 65 && sentence[i] <= 92){
            newSentence[i] = sentence[i] + 32;
        } else {
            newSentence[i] = sentence[i];
        }
    }
    newSentence[lenght] = 0;
    int counterBegin = 0;
    int counterEnd = 0;
    int wordCounter = 0;
    for (int j = 0; j < lenght; ++j) {
        if (sentence[j] == ' ' || sentence[j] == '.') {
            wordCounter++;
            counterEnd = j;
            char temp[counterEnd - counterBegin];
            for (int i = 0; i < counterEnd - counterBegin; ++i) {
                temp[i] = newSentence[counterBegin + i];
            }
            temp[counterEnd - counterBegin] = 0;
            if (strcmp(temp , word) == 0){
                return wordCounter;
            } else {
                counterBegin = counterEnd + 1;
            }
        }
    }
    return 0;
}