#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"


TEST(cake, cake1)
{
    ChocolateCake cake1(50, 50);
    GeodeCake cake2(150, 75);
    HoneyCake cake3(200, 100);
    ASSERT_EQ(3, Cake::get_total());
}