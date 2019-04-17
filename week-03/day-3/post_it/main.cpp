#include <iostream>
#include "PostIt.h"
int main() {

    PostIt o1("orange" , "Idea 1" , "blue");
    PostIt o2("pink" , "Awesome" , "black");
    PostIt o3("yellow" , "Superb!" , "green");
    std::cout << o1.getBackgroundColor() << " " << o2.getText() << " " << o3.getTextColor() << std::endl;

    return 0;
}