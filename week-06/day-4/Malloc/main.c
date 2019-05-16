#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits


int main()
{
    const int size = 10;
    int *array_ptr = (int *) malloc (sizeof(int) * size);
    array_ptr[0] = 0;
    array_ptr[1] = 1;
    array_ptr[2] = 2;
    array_ptr[3] = 3;
    array_ptr[4] = 4;

    for (int i = 0; i < size; i++){
        printf("%d\n" , array_ptr[i]);
    }
    printf("%p\n" , array_ptr);

    free(array_ptr);
    array_ptr= NULL;

    return 0;
}