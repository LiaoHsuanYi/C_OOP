#include "../src/order.h"
#include <gtest/gtest.h>

TEST(order, order1)
{
    Alcohol *alcohol1 = new Sour("Apple", 200, 0.2);
    Alcohol *alcohol2 = new Tequila("Yogurt", 300, 0.4);
    Alcohol *alcohol3 = new Sour("Lemon", 350, 0.3);
    Order order1;
    order1.append_alcohol(alcohol1);
    order1.append_alcohol(alcohol2);
    order1.append_alcohol(alcohol3);
    ASSERT_EQ(order1.get_alcohol_count(), 3);
    ASSERT_EQ(order1.get_total_price(), 850);
    delete alcohol1;
    delete alcohol2;
    delete alcohol3;
}