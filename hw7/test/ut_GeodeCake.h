#include <gtest/gtest.h>
#include "../src/geode_cake.h"
#include "../src/cake.h"

TEST(geodecake, geodecake1)
{
    GeodeCake cake1(50, 50);
    GeodeCake cake2(150, 75);
    ASSERT_EQ(2, GeodeCake::get_count());
}
TEST(geodecake, geodecake2)
{
    GeodeCake cake1(50, 50);
    ASSERT_EQ("| GeodeCake            |         50 |         50 |", cake1.to_string());
}