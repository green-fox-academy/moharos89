#include <iostream>
#include <string>
void reverse (int[] , int);
void print (int[] , int);
int main(int argc, char* args[]) {
    int aj[5] = {3 , 4, 5 , 6 , 7};
    print (aj , 5);
    reverse (aj , 5);
    print (aj , 5);




    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    return 0;
}
void reverse (int aj[] , int ajsize ){
    int c;
    for(int i= 0; i < ajsize/2 + 1; i++){
        c = aj[i];
        aj[i] = aj[ajsize-(1 + i)];
        aj[ajsize-(1 + i)] = c;
    }

}
void print (int aj[], int ajsize){
    for(int i = 0; i < ajsize; i++)
        std::cout << aj[i] << std::endl;
}