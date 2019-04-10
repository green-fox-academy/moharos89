#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> listA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    std::vector<std::string> listB = listA;
    std::string rem = "Durian";
    for (unsigned i = 0; i < listA.size(); i++) {
        if (bool ret = (listA.at(i) == "Durian")) {
            std::cout << "I have a Durian, it's number: " << i << std::endl;
        } else if (i == listA.size() - 1 && ret != 0) {
            std::cout << "I don't have a Durian" << std::endl;
        }
    }
    int remnum = rem.size();
    std::vector<std::string>::iterator remIt = listB.begin();
    listB.erase(remIt + 3);
    std::cout << listB.at(3) << std::endl;
    std::vector<std::string>::iterator addIt = listA.begin();
    listA.insert(addIt + 4, "Kiwifruit");
    std::cout << listA.at(4) << std::endl;
    int comp1 = listA.size();
    int comp2 = listB.size();
    if (comp1 / comp2 > 1) {
        std::cout << "listA is bigger, than listB" << std::endl;
    } else {
        std::cout << "ListB is bigger, than listA" << std::endl;
    }
    for (unsigned i = 0; i < listA.size(); i++) {
        if (listA.at(i) == "Avocado") {
            std::cout << "I have a Avocado, it's index: " << i << std::endl;

        }
    }
    for (unsigned i = 0; i < listB.size(); i++) {
        if (listB.at(i) == "Durian") {
            std::cout << "I have a Durian, it's index: " << i << std::endl;
        }
    }
    std::vector<std::string> newfruits = {"Passion Fruit", "Pummelo"};
    std::vector<std::string>::iterator addo = newfruits.begin();
    listB.insert(remIt + 3, addo, addo + 1);

}