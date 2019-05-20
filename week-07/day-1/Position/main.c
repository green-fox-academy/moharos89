#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void foundI(char string[]);

int main()
{
    char string[55] = "This is a string for testing";
    foundI(string);
    char *p;

    return 0;
}

void foundI(char string[])
{
    printf("%p\n", string);
    for (char *p = strtok(string, "i"); p != NULL; p = strtok(NULL, "i")) {
        if (string != p) {
            printf("%p\n", p);
        }
    }
}