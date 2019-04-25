//
// Created by Bence on 2019.04.24..
//
#include "gtest/gtest.h"
#include "myClass.h"

TEST(Appleproject , testGetAnApple) {

    myClass apple;

    //Act
    std::string result = apple.getApple();

    ASSERT_EQ(result, "apple");
}

TEST(Appleproject , TestSum) {
    myClass test;

    int sum = test.sum(&test._numbers);

    ASSERT_EQ(sum , 10);
}