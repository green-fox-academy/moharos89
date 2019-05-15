#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE *file;
    file = fopen("my-file.txt" , "w");
    fputs("The weather is rainny!\n" , file);
    fputs("I don't like it." , file);
    fclose(file);
    file = fopen("my-file.txt" , "r");
    char line[30];
    while(fgets(line , 30 , file) != NULL) {
        printf("%s" , line);
    }


    return 0;
}