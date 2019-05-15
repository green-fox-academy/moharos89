#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void multiLineWriter(char filename[], char word[], int multiplier);

int main()
{
    multiLineWriter("../proba.txt", "Man", 10);

    return 0;
}

void multiLineWriter(char filename[], char word[], int multiplier)
{
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < multiplier; i++) {
        if (i == multiplier - 1) {
            fprintf(file, "%s", word);
        } else {
            fprintf(file, "%s\n", word);
        }
    }
}