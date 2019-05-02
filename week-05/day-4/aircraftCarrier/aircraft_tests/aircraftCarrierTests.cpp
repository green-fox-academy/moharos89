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