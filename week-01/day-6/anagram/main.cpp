#include <iostream>

void isAnagram(std::string, std::string, bool);

void sorter(char, int);

int counter(std::string, int&);

char changer(std::string, char);

void swap(char, char);

int main() {

    std::cout << "Write two words" << std::endl;
    std::string word1;
    std::string word2;
    std::cin >> word1;
    std::cin >> word2;
    bool result;
    //isAnagram(word1, word2, result);
    std::cout << result << std::endl;

    std::string str = word1;
    int cnt = 0;
    for (int i = 0; str[i]; i++)
        cnt++;
    std::cout << cnt << std::endl;

    return 0;
}

void isAnagram(std::string word1, std::string word2, bool result) {
    std::string list1, list2;
    int wordsize1, wordsize2;
    char newword1 = changer(word1, counter(word1, wordsize1));
    char newword2 = changer(word2, counter(word2, wordsize2));
    sorter(newword1, counter(word2, wordsize1));

}

void sorter(char name[], int a) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (name[j] < name[j + 1]) {
                swap(name[j], name[j + 1]);
            }

        }
    }
}

int counter(std::string word, int &sizeOfWord) {
    return word.size();

}

char changer(std::string word, int a, char changedword) {
    char changeword[a];
    for (int i = 0; i < a; i++) {
        changeword[i] = word[i];
    }

}

void swap(char a, char b) {
    char c = a;
    a = b;
    b = c;
}
