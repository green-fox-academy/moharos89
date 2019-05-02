//
// Created by Bence on 2019.05.02..
//
#include "gtest/gtest.h"
#include "aircraftCarrier.h"
#include "f16.h"
#include "f35.h"

struct AircraftCarrierTest : public testing::Test {
    AircraftCarrier *boatTest;

    void SetUp()
    {
        boatTest = new AircraftCarrier();
    }

    void TearDown()
    {
        delete boatTest;
    }
};

TEST_F(AircraftCarrierTest, testAddSomePlanes)
{
    //Arrange
    F16 testPlane1;
    F35 testPlane2;
    //Act
    boatTest->add(&testPlane1);
    boatTest->add(&testPlane2);
    int result = boatTest->getWarPlanes().size();
    //Assert
    ASSERT_EQ(result , 2);

}
TEST_F(AircraftCarrierTest, testFillWithMoreAmmo)
{
    //Arrange
    F16 testPlane1;
    F35 testPlane2;
    //Act
    int basic = boatTest->getAmountOfAmmo();
    boatTest->add(&testPlane1);
    boatTest->add(&testPlane2);
    boatTest->fill();
    int result = boatTest->getAmountOfAmmo();
    //Assert
    ASSERT_EQ(result , basic - 20);

}
TEST_F(AircraftCarrierTest, testFillWithLessAmmo)
{
    //Arrange
    F16 testPlane1;
    F16 testPlane5;
    F35 testPlane2;
    F35 testPlane3;
    F35 testPlane4;

    //Act

    boatTest->add(&testPlane1);
    boatTest->add(&testPlane2);
    boatTest->add(&testPlane3);
    boatTest->add(&testPlane4);
    boatTest->add(&testPlane5);
    boatTest->fill();
    int result = boatTest->getAmountOfAmmo();
    //Assert
    ASSERT_EQ(result , 0);

}