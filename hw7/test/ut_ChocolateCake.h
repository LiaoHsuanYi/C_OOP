#include <gtest/gtest.h>
#include "../src/chocolate_cake.h"
#include "../src/cake.h"


TEST(chococake, chococake1)
{
    ChocolateCake cake1(50, 50);
    ChocolateCake cake2(150, 75);
    ASSERT_EQ(50, cake1.get_price());
    ASSERT_EQ(75, cake2.get_sweet());
    ASSERT_EQ(2, ChocolateCake::get_count());
}
TEST(chococake, chococake2)
{
    ChocolateCake cake1(50, 50);
    ASSERT_EQ("| ChocolateCake        |         50 |         50 |", cake1.to_string());
}