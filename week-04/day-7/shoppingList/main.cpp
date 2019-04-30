#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> shoppingList;
    shoppingList.insert(shoppingList.begin(), {"eggs", "milk", "fish", "apples", "bread", "chicken"});

    for (int i = 0; i < shoppingList.size(); ++i) {
        if (shoppingList[i] == "milk") {
            std::cout << "We have milk" << std::endl;
        }

    }
    for (int i = 0; i < shoppingList.size(); ++i) {
        if (shoppingList[i] == "bananas") {
            std::cout << "We have bananas" << std::endl;
        } else if (shoppingList[i] != "bananas" && i == shoppingList.size() - 1) {
            std::cout << "There is no bananas" << std::endl;
        }
    }

    std::vector<std::string>::iterator vectorIt = shoppingList.begin();
    for (vectorIt; vectorIt != shoppingList.end(); vectorIt++) {
        std::cout << *vectorIt << std::endl;
    }
    std::vector<std::string>::reverse_iterator vectrorIt = shoppingList.rbegin();
    for (vectrorIt; vectrorIt != shoppingList.rend(); vectrorIt++) {
        std::cout << *vectrorIt << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}