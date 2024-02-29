#include <gtest/gtest.h>
#include "../src/sandwich.h"
#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
#include "../src/sweet_sandwich.h"

TEST(sandfac, sandfac1)
{
    SweetSandwich* sweet_sandwich = SandwichFactory<SweetSandwich>::create_sandwich(15, 32767);
    ASSERT_EQ(15, sweet_sandwich->get_price());
    ASSERT_EQ(32767, sweet_sandwich->get_id());
    delete sweet_sandwich;
}
TEST(sandfac, sandfac2)
{
    std::vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33, 44, 55, 66, 99});
    ASSERT_EQ(33, sweet_sandwich_set[0]->get_id());
    ASSERT_EQ(15, sweet_sandwich_set[1]->get_price());
    for (int i = 0; i < sweet_sandwich_set.size(); i++)
    {
        delete sweet_sandwich_set[i];
    }
    ASSERT_THROW(std::vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, -5, {33, 44}), std::invalid_argument);
}