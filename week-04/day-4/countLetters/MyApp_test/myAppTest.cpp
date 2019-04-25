//
// Created by Bence on 2019.04.24..
//
#include "gtest/gtest.h"
#include "myClass.h"

TEST(countLettersProject, testUniqueLetterCheckerTrue) {
    //Arrange
    char letter = {'r'};
    std::vector<char> letters = {'z', 'e', 't'};

    //Act
    bool result = uniqueLetterChecker(letter, letters);
    //Assert
    ASSERT_EQ(result, true);
}

TEST(countLettersProject, testUniqueLetterCheckerFalse) {
    //Arrange
    char letter = {'r'};
    std::vector<char> letters = {'z', 'e', 't', 'r'};

    //Act
    bool result = uniqueLetterChecker(letter, letters);
    //Assert
    ASSERT_EQ(result, false);
}

TEST(countLettersProject, testUniqueLetterVectorMaker) {
    //Arrange
    std::string word = "root";
    std::vector<char> letters;

    //Act
    letters = uniquletter(word);
    //Assert
    ASSERT_EQ(letters[0], word[0]);
}
TEST(countLettersProject, testUniqueLetterVectorMaker2) {
    //Arrange
    std::string word = "root";
    std::vector<char> letters;

    //Act
    letters = uniquletter(word);
    //Assert
    ASSERT_EQ(letters[1], word[2]);
}
TEST(countLettersProject, testUniqueLetterVectorMaker3) {
    //Arrange
    std::string word = "root";
    std::vector<char> letters;

    //Act
    letters = uniquletter(word);
    bool result = letters[2] == word[2];
    //Assert
    ASSERT_EQ(result, false);
}
TEST(countLettersProject, testDictionaryMakerCompleted) {
    //Arrange
    std::string word = "root";

    //Act
    std::map<std::string , int> testMap = dictionaryMaker(word);

    //Assert
    ASSERT_EQ(testMap["o"], 2);
}
TEST(countLettersProject, testDictionaryMakerCompleted2) {
    //Arrange
    std::string word = "root";

    //Act
    std::map<std::string , int> testMap = dictionaryMaker(word);

    //Assert
    ASSERT_EQ(testMap["r"], 1);
}
TEST(countLettersProject, testDictionaryMakerCompletedNotMatched) {
    //Arrange
    std::string word = "root";

    //Act
    std::map<std::string , int> testMap = dictionaryMaker(word);

    //Assert
    ASSERT_NE(testMap["z"], 1);
}