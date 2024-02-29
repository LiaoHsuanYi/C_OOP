#include <gtest/gtest.h>
#include "../src/honey_cake.h"
#include "../src/cake.h"

TEST(honeycake, honeycake1)
{
    HoneyCake cake1(50, 50);
    HoneyCake cake2(150, 75);
    ASSERT_EQ(2, HoneyCake::get_count());
}
TEST(honeycake, honeycake2)
{
    HoneyCake cake1(50, 50);
    ASSERT_EQ("| HoneyCake            |         50 |         50 |", cake1.to_string());
}