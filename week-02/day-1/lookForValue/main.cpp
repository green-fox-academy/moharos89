#include <iostream>

int luke( int [] , int , int);

int main()
{
    int array [10] = {2 , 3 , 4 , 5 , 6 , 7 , 11 , 23 , 54 , 32};
    int arraysize = sizeof(array)/sizeof(array[0]);
    int number = 5;
    luke (array , arraysize , number);
    std::cout << luke(array , arraysize , number) ;
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    return 0;
}
int luke (int array[] , int arraysize, int c){

    for(int i = 0; i < arraysize; i++) {
        if (c == array[i]) {
            return i;
        }
        if (i == (arraysize - 1)) {
            return -1;
        }
    }

}