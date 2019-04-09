#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    std::string todoText = " - Buy milk\n";
    todoText = "My todo: \n" + todoText;
    std::string back1 = " - Download games";
    todoText.append(" - Download games\n");
    std::string back2 = "   - Diablo";
    int back1size = back1.size();
    int back2size = back2.size();
    std::cout << todoText.capacity() << std::endl;
    std::cout << todoText.size() << std::endl;

    todoText.insert(todoText.size() , back2);


    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    std::cout << todoText << std::endl;

    return 0;
}