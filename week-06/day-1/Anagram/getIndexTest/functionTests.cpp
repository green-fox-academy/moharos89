//
// Created by Bence on 2019.05.13..
//
#include <gtest/gtest.h>
#include "functions.h"
#include "numbers.h"

TEST(numberConverter , TestWriteOutEight)
{
    //Arrange
    int number = 8;
    //Act
    std::string result = numberConverter(number);
    //Assert
    ASSERT_EQ(result , "eight");
}

TEST(numberConverter , TestWriteOutZeroToTen)
{
    //Arrange
    int number = 19;
    //Act
    std::string result = numberConverter(number);
    //Assert
    ASSERT_EQ(result , "nineteen");
}

TEST(numberConverter , TestWriteOutZeroTo_99)
{
    //Arrange
    int number = 55;
    //Act
    std::string result = numberConverter(number);
    //Assert
    ASSERT_EQ(result , "fifty-five");
}