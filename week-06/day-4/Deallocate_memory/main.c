#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    const int size = 10;
    int *pointer = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        pointer[i] = i * 2;
    }
    for (int j = 0; j < 10 ; ++j) {
        printf("%d\n" , pointer[j]);
    }

    free(pointer);
    pointer = NULL;

    return 0;
}