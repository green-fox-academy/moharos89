#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int distance(char string[]);

int main ()
{
    char str[] = "This is a sample string";
    char *first, *last;
    printf("%d\n" , distance(str));

    return 0;
}

int distance(char string[])
{
    char *first = NULL;
    char *last = NULL;
    first = strpbrk(string , "s");
    for (char *p = strtok(string , " "); p != NULL; p = strtok(NULL , " ")){
        last = strpbrk(p , "s");
    }
    return last - first - 1;
}