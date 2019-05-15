#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subString(char word1[], char word2[]);
int subString2(char word1[], char word2[]);

int main()
{
    puts("Write down two word");
    char word1[10];
    char word2[10];
    gets(word1);
    gets(word2);
    printf("%d\n" , subString(word1 , word2));
    printf("%d\n" , subString2(word1 , word2));


    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    return 0;
}

int subString(char word1[], char word2[])
{
    if (strlen(word1) == strlen(word2)) {
        return -1;
    } else if (strlen(word1) >= strlen(word2)) {
        for (int i = 0; i < strlen(word1); i++) {
            if (word1[i] == word2[0]) {
                char temp[11] = "";
                for (int j = 0; j < strlen(word2); j++) {
                    char tempChar[2];
                    tempChar[0] = word1[i+j];
                    tempChar[1] = 0;
                    strcat(temp , tempChar);
                }
                if(!strcmp(word2 , temp)){
                    return 1;
                }
            }
        }
        return 0;
    } else {
        for (int i = 0; i < strlen(word2); i++) {
            if (word2[i] == word1[0]) {
                char temp[11] = "";
                for (int j = 0; j < strlen(word1); j++) {
                    char tempChar[2];
                    tempChar[0] = word2[i+j];
                    tempChar[1] = 0;
                    strcat(temp , tempChar);
                }
                if(!strcmp(word1 , temp)){
                    return 1;
                }
            }
        }
        return 0;
    }
}

int subString2(char word1[], char word2[])
{
    if (strlen(word1) == strlen(word2)) {
        return -1;
    } else if (strlen(word1) >= strlen(word2)) {
        for (int i = 0; i < strlen(word1); i++) {
            if (word1[i] == word2[0]) {
                for (int j = 0; j < strlen(word2); j++) {
                    if (word1[i + j] != word2[j]){
                        break;
                    } else if (j == strlen(word2) - 1) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    } else {
        for (int i = 0; i < strlen(word2); i++) {
            if (word2[i] == word1[0]) {
                for (int j = 0; j < strlen(word1); j++) {
                    if (word2[i + j] != word1[j]){
                        break;
                    } else if (j == strlen(word1) - 1) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
}