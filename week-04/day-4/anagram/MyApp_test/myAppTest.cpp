//
// Created by Bence on 2019.04.24..
//
#include "gtest/gtest.h"
#include "myClass.h"

TEST(anagram , testWordSizeCheckerEqual) {
    //Arrange

    std::string word1 = "rod";
    std::string word2 = "god";

    //Act

    bool result = wordSizeChecker(word1 , word2);

    //Assert
    ASSERT_EQ(result , true);
}
TEST(anagram , testWordSizeCheckerNotEqual) {
    //Arrange
    std::string word1 = "road";
    std::string word2 = "god";

    //Act

    bool result = wordSizeChecker(word1 , word2);

    //Assert
    ASSERT_EQ(result , false);
}
TEST(anagram , testSwitcher) {
    //Arrange
    std::string wordtest = "ogd";

    //Act
    switcher(wordtest[0] , wordtest[1]);

    //Assert
    ASSERT_EQ(wordtest , "god");
}
TEST(anagram , testWordSorter) {
    //Arrange
    std::string word1 = "rod";


    //Act

    std::string result = wordSorter(word1);

    //Assert
    ASSERT_EQ(result , "dor");
}
TEST(anagram , testAnagramtrue) {
    //Arrange

    std::string word1 = "dog";
    std::string word2 = "god";

    //Act

    bool result = anagram(word1 , word2);

    //Assert
    ASSERT_EQ(result , true);
}
TEST(anagram , testAnagramSizeFailure) {
    //Arrange
    std::string word1 = "road";
    std::string word2 = "god";

    //Act

    bool result = anagram(word1 , word2);

    //Assert
    ASSERT_EQ(result , false);
}
TEST(anagram , testAnagramFailure) {
    //Arrange

    std::string word1 = "rod";
    std::string word2 = "god";

    //Act

    bool result = anagram(word1 , word2);

    //Assert
    ASSERT_EQ(result , false);
}