#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void printer (int *arrayptr[] ,int row , int column);
int main() {

    int array[3][4] = {
            {1 , 2 , 3 , 4} ,
            {3 , 2 , 1 , 5} ,
            {2 , 3 , 1 , 6}
    };

    int n = sizeof(array) / sizeof(array[0]);
    int m= sizeof(array) / n / sizeof(array[0][0]);
    int *arrayptr[n];
    for (int i = 0; i < n; i++) {
        arrayptr[i] = &array[i][0];
    }
    std::cout << n << " " << m << std::endl;
    printer(arrayptr , n , m);

    std::cout << "Hello, World!" << std::endl;


    std::ifstream file("../CMakeLists.txt");
    std::string line;
    while (std::getline(file , line)) {
        std::cout << line << std::endl;
        std::stringstream ss(line);
        std::string words;
        while (std::getline(ss , words , ' ')){
            std::cout << words << std::endl;
        }
    }


    return 0;
}

void printer (int *arrayptr[] , int row , int column) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; ++j) {
            std::cout << arrayptr[i][j] << " ";

        }
        std::cout << std::endl;
    }

}
