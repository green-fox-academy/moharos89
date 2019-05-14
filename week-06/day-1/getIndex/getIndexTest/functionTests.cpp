//
// Created by Bence on 2019.05.13..
//
#include <gtest/gtest.h>
#include "functions.h"

TEST(getIndex, testGetListAndValueAndReturn)
{
    //Arrange
    std::vector<int> testVector = {1, 23, 3};
    int value = 2;

    //Act
    int result = getIndex(testVector , value);

    //Assert
    ASSERT_EQ(result , -1);
}

TEST(getIndex, testGetEmptyList)
{
    //Arrange
    std::vector<int> testVector;
    int value = 2;

    //Act
    int result = getIndex(testVector , value);

    //Assert
    ASSERT_EQ(result , -1);
}

TEST(getIndex, testGetListAndValueAndReturnIndex)
{
    //Arrange
    std::vector<int> testVector = {1, 23, 3};
    int value = 23;

    //Act
    int result = getIndex(testVector , value);

    //Assert
    ASSERT_EQ(result , 1);
}

TEST(getIndex, testGetListAndValueAndReturnIndexFirst)
{
    //Arrange
    std::vector<int> testVector = {1, 23, 3};
    int value = 1;

    //Act
    int result = getIndex(testVector , value);

    //Assert
    ASSERT_EQ(result , 0);
}