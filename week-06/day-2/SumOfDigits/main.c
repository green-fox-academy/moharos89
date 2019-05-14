#include <stdio.h>
#include <stdlib.h>

int isSumDigits(int *a, int *b);

int sumDigits(int a);


int main()
{
    printf("Write two numbers!\n");
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", isSumDigits(&a, &b));

    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    return 0;
}

int sumDigits(int a)
{
    int sum = 0;
    if (a / 10 == 0) {
        return sum += a % 10;
    } else {
        sum += a % 10;
        return sum += sumDigits(a / 10);
    }
}

int isSumDigits(int *a, int *b)
{
    int sumA = sumDigits(*a);
    int sumB = sumDigits(*b);
    if (sumA == sumB) {
        return 1;
    } else {
        return 0;
    }
}