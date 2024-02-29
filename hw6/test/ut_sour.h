#include "../src/sour.h"
#include <gtest/gtest.h>

TEST(sour, sour1)
{
    ASSERT_THROW(Sour("", 200, 0.2), std::invalid_argument);
    ASSERT_THROW(Sour("Apple", -200, 0.2), std::invalid_argument);
    ASSERT_THROW(Sour("Apple", 200, -0.2), std::invalid_argument);
}
TEST(sour, sour2)
{
    Sour sour("Apple", 200, 0.2);
    ASSERT_EQ(sour.get_name(), "Apple");
    ASSERT_EQ(sour.get_price(), 200);
    ASSERT_EQ(sour.get_alcohol_content(), 0.2);
}
TEST(sour, sour3)
{
    Sour sour;
    Sour sour1("Apple", 200, 0.2);
    Sour sour2("Yogurt", 300, 0.4);
    sour = sour1 + sour2;
    ASSERT_EQ(sour.get_name(), "Apple");
    ASSERT_EQ(sour.get_price(), 500);
    ASSERT_NEAR(sour.get_alcohol_content(), 0.3, 0.01);
}
TEST(sour, sour4)
{
    Sour sour1("Apple", 200, 0.2);
    Sour sour2("Yogurt", 300, 0.4);
    ASSERT_FALSE(sour1 == sour2);
}
TEST(sour, sour5)
{
    Sour sour1("Apple", 200, 0.2);
    Sour sour2("Apple", 200, 0.2);
    ASSERT_TRUE(sour1 == sour2);
}
TEST(sour, sour6)
{
    Sour sour("Apple", 200, 0.2);
    sour.dilute();
    ASSERT_NEAR(sour.get_alcohol_content(), 0.14, 0.01);
}