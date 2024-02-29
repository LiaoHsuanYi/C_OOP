#include <gtest/gtest.h>
#include "../src/length.h"
TEST(Length, TwoDim)
{
    double arr[] = {3, 4};
    int dim = 2;
    double output = length(arr, dim);
    ASSERT_EQ(output , 5);
}

TEST(Length, ThreeDim)
{
    double arr[] = {3, 4, 5};
    int dim = 3;
    double output = length(arr, dim);
    ASSERT_NEAR(output , 7.07, 0.01);
}
TEST(Length, TwoDimMathVector)
{
    double arr[] = {3, 4};
    int dim = 2;
    //MathVector m(); -> default constructor
    MathVector m(dim, arr);
    double output = length(m); //copy constructor
    //ASSERT_EQ(output , 5);
}