#include <iostream>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;

    double bmi = massInKg / (heightInM * heightInM);

    std::cout << bmi << std::endl;

    // Print the Body mass index (BMI) based on these values

    return 0;
}