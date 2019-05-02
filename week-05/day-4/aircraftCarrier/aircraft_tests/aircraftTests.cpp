//
// Created by Bence on 2019.05.02..
//

#include <gtest/gtest.h>
#include <f35.h>
#include "f16.h"

TEST(F16, testSet_getAmmo) {
    //Arrange
    F16 f16test1;
    int ammo = 12;
    //Act
    f16test1.setAmmo(ammo);

    //Assert
    ASSERT_EQ(f16test1.getAmmo(), 12);
}

TEST(F16, testRefillWithMoreThanCapacityAndCheckAmmo) {
    //Arrange
    F16 f16test1;
    //Act
    f16test1.refill(23);

    //Assert
    ASSERT_EQ(f16test1.getAmmo(), 8);
}

TEST(F16, testRefillWithMoreThanCapacityAndTestReturnValue) {
    //Arrange
    F16 f16test1;
    //Act
    int result = f16test1.refill(23);

    //Assert
    ASSERT_EQ(result, 23 - 8);
}

TEST(F16, testRefillWithLessThanCapacityAndCheckAmmo) {
    //Arrange
    F16 f16test1;
    //Act
    f16test1.refill(4);

    //Assert
    ASSERT_EQ(f16test1.getAmmo(), 4);
}

TEST(F16, testRefillWithLessThanCapacityAndTestReturnValue) {
    //Arrange
    F16 f16test1;
    //Act
    int result = f16test1.refill(5);

    //Assert
    ASSERT_EQ(result, 0);
}
TEST(F16, testFightWithFullAmmo) {
    //Arrange
    F16 f16test1;
    //Act
    f16test1.refill(8);
    int result = f16test1.fight();

    //Assert
    ASSERT_EQ(result, 8 * 30);
}
TEST(F16, testFightWithNoFullAmmo) {
    //Arrange
    F16 f16test1;
    //Act
    f16test1.refill(3);
    int result = f16test1.fight();

    //Assert
    ASSERT_EQ(result, 3 * 30);
}
TEST(F16, testFightWithNoAmmo) {
    //Arrange
    F16 f16test1;
    //Act
    int result = f16test1.fight();

    //Assert
    ASSERT_EQ(result, 0);
}
TEST(F16, testPriority) {
    //Arrange
    F16 f16test1;
    //Act
    bool result = f16test1.isPriority();

    //Assert
    ASSERT_EQ(result, false);
}
TEST(F35, testSet_getAmmo) {
//Arrange
F35 f35test1;
int ammo = 10;
//Act
f35test1.setAmmo(ammo);

//Assert
ASSERT_EQ(f35test1.getAmmo(), 10);
}

TEST(F35, testRefillWithMoreThanCapacityAndCheckAmmo) {
    //Arrange
    F35 f35test1;
    //Act
    f35test1.refill(23);

    //Assert
    ASSERT_EQ(f35test1.getAmmo(), 12);
}

TEST(F35, testRefillWithMoreThanCapacityAndTestReturnValue) {
    //Arrange
    F35 f35test1;
    //Act
    int result = f35test1.refill(23);

    //Assert
    ASSERT_EQ(result, 23 - 12);
}

TEST(F35, testRefillWithLessThanCapacityAndCheckAmmo) {
    //Arrange
    F35 f35test1;
    //Act
    f35test1.refill(4);

    //Assert
    ASSERT_EQ(f35test1.getAmmo(), 4);
}

TEST(F35, testRefillWithLessThanCapacityAndTestReturnValue) {
    //Arrange
    F35 f35test1;
    //Act
    int result = f35test1.refill(5);

    //Assert
    ASSERT_EQ(result, 0);
}
TEST(F35, testFightWithFullAmmo) {
    //Arrange
    F35 f35test1;
    //Act
    f35test1.refill(12);
    int result = f35test1.fight();

    //Assert
    ASSERT_EQ(result, 12 * f35test1.getBaseDamage());
}
TEST(F35, testFightWithNoFullAmmo) {
    //Arrange
    F35 f35test1;
    //Act
    f35test1.refill(3);
    int result = f35test1.fight();

    //Assert
    ASSERT_EQ(result, 3 * f35test1.getBaseDamage());
}
TEST(F35, testFightWithNoAmmo) {
    //Arrange
    F35 f35test1;
    //Act
    int result = f35test1.fight();

    //Assert
    ASSERT_EQ(result, 0);
}
TEST(F35, testPriority) {
    //Arrange
    F35 f35test1;
    //Act
    bool result = f35test1.isPriority();

    //Assert
    ASSERT_EQ(result, true);
}