#include <stdio.h>
#include <stdlib.h>

int isPrime(int a);

int main()
{
    printf("Give me a number!\n");
    int a;
    scanf("%d", &a);
    printf("%d\n" , isPrime(a));
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    return 0;
}

int isPrime(int a)
{
    if(a != 0 && a != 1){
        for(int i = 2; i < a; i++){
            if (a % i == 0){
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}
