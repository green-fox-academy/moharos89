#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

void sorter(int *array, int sizeOfMatrix);

int percentile(int *array, int sizeOfMatrix , int number);

int main()
{
    int sizeOfMatrix;
    puts("Give me the size of the matrix!");
    scanf("%d", &sizeOfMatrix);
    int *array = (int *) malloc(sizeOfMatrix * sizeof(int));
    puts("Give me the numbers of the matrix!");
    for (int i = 0; i < sizeOfMatrix; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n" , percentile(array , sizeOfMatrix , 80));
    printf("%d\n" , percentile(array , sizeOfMatrix , 90));

    free(array);
    array = NULL;
    return 0;
}

int percentile(int *array, int sizeOfMatrix , int number)
{
    sorter(array, sizeOfMatrix);
    float value = ((float) number / (float) 100 * (float) sizeOfMatrix);
    if(value - (int) value == 0) {
        return array[(int)value - 1];
    } else {
        int average = (array[(int) value - 1] + array[(int) value]) / 2;
        return average;
    }

}

void sorter(int *array, int sizeOfMatrix)
{
    for (int i = 0; i < sizeOfMatrix; ++i) {
        for (int j = 0; j < sizeOfMatrix; ++j) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}