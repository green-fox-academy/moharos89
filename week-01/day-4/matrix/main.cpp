#include <iostream>
#include <string>

void make_array(int a, int b);

int main(int argc, char *args[]) {

    std::cout << "Give me 2 number" << std::endl;
    int a;
    int b;
    std::cin >> a >> b;
    make_array(a, b);


    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    return 0;
}

void make_array(int a, int b) {
    int array[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (j == i) {
                array[i][j] = 1;
            } else {
                array[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j) {
                std::cout << array[i][j];
            } else if ( j == b){
                std::cout << std::endl;
            }
            else {
                std::cout << array[i][j];
            }
        }

    }

}
