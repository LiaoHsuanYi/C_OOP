#include <gtest/gtest.h>
#include "../src/chocolate_cake.h"
#include "../src/cake_showcase.h"
#include "../src/cake.h"

TEST(cakeshow, cakeshow1)
{
    ChocolateCake cake1(50, 50);
    ChocolateCake cake2(150, 75);
    ChocolateCake cake3(200, 110);
    ChocolateCake *array[3] = {&cake1, &cake2, &cake3};
    CakeShowcase<ChocolateCake> cakeshow(3, array);
    ASSERT_EQ(400, cakeshow.calc_total_price());
    ASSERT_EQ(235, cakeshow.calc_total_sweet());
    ASSERT_THROW(cakeshow[3], std::out_of_range);
}
TEST(cakeshow, cakeshow2)
{
    ChocolateCake cake1(50, 50);
    ChocolateCake cake2(150, 75);
    ChocolateCake cake3(200, 110);
    ChocolateCake *array[3] = {&cake1, &cake2, &cake3};
    CakeShowcase<ChocolateCake> cakeshow(3, array);
    std::string a = 
    "| CakeName             | Price      | Sweet      |\n"
    "| -------------------- | ---------- | ---------- |\n"
    "| ChocolateCake        |         50 |         50 |\n"
    "| ChocolateCake        |        150 |         75 |\n"
    "| ChocolateCake        |        200 |        110 |\n"
    "| -------------------- | ---------- | ---------- |";
    ASSERT_EQ(a, cakeshow.to_string());
}