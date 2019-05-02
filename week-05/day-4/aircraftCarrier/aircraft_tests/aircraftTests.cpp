//
// Created by Bence on 2019.05.02..
//

#include <gtest/gtest.h>
#include "f16.h"

TEST(F16 , testSet_getAmmo) {
    //Arrange
    F16 f16test1;
    int ammo = 12;
    //Act
    f16test1.setAmmo(ammo);

    //Assert
    ASSERT_EQ(f16test1.getAmmo(), 12);
}
TEST(F16 , testRefillWithMoreThanCapacityAndCheckAmmo) {
    //Arrange
    F16 f16test1;
    //Act
    f16test1.refill(23);

    //Assert
    ASSERT_EQ(f16test1.getAmmo(), 8);
}