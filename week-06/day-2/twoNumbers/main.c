#include <stdio.h>

int main()
{
    int num1 = 22;
    int num2 = 13;
    int sum = num1 + num2;
    int sub = num1 - num2;
    int multi = num1 * num2;
    float divide = (float) num1 / (float) num2;
    int rem = num1 % num2;
    printf("Sum= %d\nSub= %d\nMulti= %d\nDivide= %.2f\nRem= %d\n", sum, sub, multi, divide, rem);

    //Readable solution
    printf("Sum= %d\n", sum);
    printf("Sub= %d\n", sub);
    printf("Multi= %d\n", multi);
    printf("Divide= %.2f\n", divide);
    printf("Rem= %d\n", rem);
    return 0;
}