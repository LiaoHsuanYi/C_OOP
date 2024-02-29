#include "../src/tequila.h"
#include <gtest/gtest.h>

TEST(tequila, tequila1)
{
    ASSERT_THROW(Tequila("", 200, 0.2), std::invalid_argument);
    ASSERT_THROW(Tequila("Apple", -200, 0.2), std::invalid_argument);
    ASSERT_THROW(Tequila("Apple", 200, -0.2), std::invalid_argument);
}
TEST(tequila, tequila2)
{
    Tequila tequila("Apple", 200, 0.2);
    ASSERT_EQ(tequila.get_name(), "Apple");
    ASSERT_EQ(tequila.get_price(), 200);
    ASSERT_EQ(tequila.get_alcohol_content(), 0.2);
}
TEST(tequila, tequila3)
{
    Tequila tequila;
    Tequila tequila1("Apple", 200, 0.2);
    Tequila tequila2("Yogurt", 300, 0.4);
    tequila = tequila1 + tequila2;
    ASSERT_EQ(tequila.get_name(), "Apple");
    ASSERT_EQ(tequila.get_price(), 500);
    ASSERT_NEAR(tequila.get_alcohol_content(), 0.3, 0.01);
}
TEST(tequila, tequila4)
{
    Tequila tequila1("Apple", 200, 0.2);
    Tequila tequila2("Yogurt", 300, 0.4);
    ASSERT_FALSE(tequila1 == tequila2);
}
TEST(tequila, tequila5)
{
    Tequila tequila1("Apple", 200, 0.2);
    Tequila tequila2("Apple", 200, 0.2);
    ASSERT_TRUE(tequila1 == tequila2);
}
TEST(tequila, tequila6)
{
    Tequila tequila("Apple", 200, 0.2);
    tequila.dilute();
    ASSERT_NEAR(tequila.get_alcohol_content(), 0.19, 0.01);
}