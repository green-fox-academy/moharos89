#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE *file;
    file = fopen("../my-file.txt" , "w");
    fprintf(file , "Bence Moharos");
    fclose(file);

    return 0;
}