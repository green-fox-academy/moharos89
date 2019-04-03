#include <iostream>
#include <string>
#include <math.h>

int main(int argc, char* args[]) {

    int favnum = 9;
    std::cout << "My favorit number is: " << favnum << std::endl << std::endl;

    int a = 123;
    int b = 526;
    int c = a;
    a = b;
    b = c;
    std::cout << a << std::endl;
    std::cout << b << std::endl << std::endl;
    std::string name = "Bence Moharos";
    int age = 29;
    double h = 1.71;
    bool m = false;
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << h << std::endl;
    std::cout << m << std::endl << std::endl;

    int d = 3;
    // make the "a" variable's value bigger by 10
    d += 10;

    std::cout << d << std::endl;

    int e = 100;
    // make b smaller by 7
    e -= 7;

    std::cout << e << std::endl;

    int k = 44;
    // please double c's value
    k += k;

    std::cout << k << std::endl;

    int l = 125;
    // please divide by 5 d's value

    l /= (5 * l);


    std::cout << l << std::endl;

    int n = 8;
    // please cube of e's value
    n *= n;
    n *= 8;
    std::cout << n << std::endl;

    int f1 = 123;
    int f2 = 345;
    // tell if f1 is bigger than f2 (print as a boolean)
    bool ter = f1 > f2;
    std::cout << ter << std::endl;

    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    bool ret = (g2 *= 2) > g1;
    std::cout << ret << std::endl;

    int o = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)
    bool her = (o %= 11) == 0;
    std::cout << her << std::endl;
    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    bool zer = (i1 > (i2 * i2)) && (i1 < (i2 * i2 * i2));
    std::cout << zer << std::endl;


    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    bool wer = ((j % 3) == 0) || ((j % 5) == 0);
    std::cout << wer << std::endl << std::endl;

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    int rtime = (24 * 60 * 60) - ((14* 60 * 60) + (34 * 60) + 42);
    std::cout << "Remaining time: " << rtime << std::endl;




    return 0;
}