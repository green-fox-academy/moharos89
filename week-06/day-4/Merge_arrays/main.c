#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

void arrayFiller(int **arrayPtr, int number);

void sorter(int *arrayptr);

int main()
{
    const int size = 10;
    int *arrayPtr1 = (int *) malloc(size * sizeof(int));
    int *arrayPtr2 = (int *) malloc(size * sizeof(int));
    arrayFiller(&arrayPtr1, 0);
    arrayFiller(&arrayPtr2, 1);
    arrayPtr1 = realloc(arrayPtr1, size * 2 * sizeof(int));
    for (int i = 0; i < size; ++i) {
        arrayPtr1[10 + i] = arrayPtr2[i];
    }
    sorter(arrayPtr1);
    for (int j = 0; j < size * 2; ++j) {
        printf("%d\n", arrayPtr1[j]);
    }

    free(arrayPtr1);
    free(arrayPtr2);
    arrayPtr1 = NULL;
    arrayPtr2 = NULL;

    return 0;
}

void arrayFiller(int **arrayPtr, int number)
{
    for (int i = 0; i < 10; ++i) {
        arrayPtr[0][i] = i * 2 + number;
    }
}

void sorter(int *arrayptr)
{
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (arrayptr[i] > arrayptr[j]) {
                int temp = arrayptr[i];
                arrayptr[i] = arrayptr[j];
                arrayptr[j] = temp;
            }
        }
    }
}