#include "../src/algorithm.h"
#include "../src/order.h"
#include "../src/sour.h"
#include "../src/tequila.h"
#include "../src/alcohol.h"
#include <gtest/gtest.h>


TEST(algorithm, algorithm1)
{
    Alcohol *alcohol1 = new Sour("Apple", 200, 0.2);
    Alcohol *alcohol2 = new Tequila("Yogurt", 300, 0.4);
    Alcohol *alcohol3 = new Sour("Lemon", 350, 0.3);
    Order order1;
    order1.append_alcohol(alcohol1);
    order1.append_alcohol(alcohol2);
    order1.append_alcohol(alcohol3);
    sort_alcohol_by_content(order1.alcohol);
    Alcohol *max;
    max = get_greatest_content_of_alcohol(order1.alcohol);
    ASSERT_NEAR(max->get_alcohol_content(), 0.4, 0.01);
    ASSERT_EQ(max->get_name(), "Yogurt");
    delete alcohol1;
    delete alcohol2;
    delete alcohol3;
}

TEST(algorithm, algorithm2)
{
    Alcohol *alcohol1 = new Sour("Apple", 200, 0.2);
    Alcohol *alcohol2 = new Tequila("Yogurt", 300, 0.4);
    Alcohol *alcohol3 = new Sour("Lemon", 350, 0.3);
    Order order1;
    order1.append_alcohol(alcohol1);
    order1.append_alcohol(alcohol2);
    order1.append_alcohol(alcohol3);
    sort_alcohol_by_content(order1.alcohol);
    Alcohol *min;
    min = get_smallest_content_of_alcohol(order1.alcohol);
    ASSERT_NEAR(min->get_alcohol_content(), 0.2, 0.01);
    ASSERT_EQ(min->get_name(), "Apple");
    delete alcohol1;
    delete alcohol2;
    delete alcohol3;
}

TEST(algorithm, algorithm3)
{
    Alcohol *alcohol1 = new Sour("Apple", 200, 0.2);
    Alcohol *alcohol2 = new Tequila("Yogurt", 300, 0.4);
    Alcohol *alcohol3 = new Sour("Lemon", 350, 0.3);
    Order order1;
    order1.append_alcohol(alcohol1);
    order1.append_alcohol(alcohol2);
    order1.append_alcohol(alcohol3);
    sort_alcohol_by_name(order1.alcohol);
    ASSERT_EQ(order1.alcohol[0]->get_name(), "Apple");
    delete alcohol1;
    delete alcohol2;
    delete alcohol3;
}

TEST(algorithm, algorithm4)
{
    Alcohol *alcohol1 = new Sour("Apple", 200, 0.3);
    Alcohol *alcohol2 = new Tequila("Yogurt", 300, 0.3);
    Alcohol *alcohol3 = new Sour("Lemon", 350, 0.3);
    Order order1;
    order1.append_alcohol(alcohol1);
    order1.append_alcohol(alcohol2);
    order1.append_alcohol(alcohol3);
    sort_alcohol_by_content(order1.alcohol);
    reverse(begin(order1.alcohol), end(order1.alcohol));
    Alcohol *max;
    max = order1.alcohol[0];
    ASSERT_EQ(max->get_name(), "Yogurt");
    delete alcohol1;
    delete alcohol2;
    delete alcohol3;
}

TEST(algorithm, algorithm5)
{
    Alcohol *alcohol1 = new Sour("Apple", 200, 0.3);
    Alcohol *alcohol2 = new Tequila("Yogurt", 300, 0.4);
    Alcohol *alcohol3 = new Sour("Lemon", 350, 0.3);
    Order order1;
    order1.append_alcohol(alcohol1);
    order1.append_alcohol(alcohol2);
    order1.append_alcohol(alcohol3);
    sort_alcohol_by_content(order1.alcohol);
    Alcohol *min;
    min = order1.alcohol[0];
    ASSERT_EQ(min->get_name(), "Apple");
    delete alcohol1;
    delete alcohol2;
    delete alcohol3;
}