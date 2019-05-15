#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int lineCounter(char fileName[]);

int main ()
{
    FILE *file;
    file = fopen("../proba.txt" , "w");
    fputs("AP\n" , file);
    fputs("P\n" , file);
    fputs("L\n" , file);
    fputs("E" , file);
    fclose(file);
    char fileName[] = "../proba.txt";
    printf("%d\n" , lineCounter(fileName));



    return 0;
}

int lineCounter(char fileName[]){
    FILE *file;
    if (file = fopen(fileName , "r")) {
        int counter = 0;
        char line[10] = "";
        while (!feof(file)) {
            fscanf(file , "%s" , &line);
            if(strtok(line , "\n")) {
                counter++;
            }
        }
        fclose(file);
        return counter;
    } else {
        return 0;
    }
}