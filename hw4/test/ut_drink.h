#include "../src/drink.h"
#include<gtest/gtest.h>

TEST(drink, drink1)
{
    Drink drink("Black Tea", 0.3, 30); 
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.3);
    ASSERT_EQ(drink.getPrice(), 30);
}
TEST(drink, drink2)
{ 
    Drink drink("Green Tea", 0.3, 30);
    drink.addTopping(Topping ("Bubble", 0.1, 10));
    ASSERT_EQ(drink.getName(), "Green Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.4);
    ASSERT_EQ(drink.getPrice(), 40);
}
TEST(drink, drink3)
{
    ASSERT_THROW(Drink ("Tea", 0.3, 30), std::string);
}
TEST(drink, drink4)
{
    ASSERT_THROW(Drink ("Black Tea", -0.3, 30), std::string);
}
TEST(drink, drink5)
{
    ASSERT_THROW(Drink ("Green Tea", 0.3, -10), std::string);
}
TEST(drink, drink6)
{ 
    Drink drink("Green Tea", 0.3, 30);
    drink.addTopping(Topping ("Bubble", 0.1, 10));
    drink.addTopping(Topping ("Pudding", 0.15, 15));
    ASSERT_THROW(drink.getToppingByIndex(5),std::string);
}
TEST(drink, drink7)
{
    Drink some_drink("Black Tea", 0.3, 30);
    Drink drink;
    drink = some_drink; 
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.3);
    ASSERT_EQ(drink.getPrice(), 30);
}
TEST(drink, drink8)
{ 
    Drink drink("Green Tea", 0.3, 30);
    drink.addTopping(Topping ("Bubble", 0.1, 10));
    drink.addTopping(Topping ("Pudding", 0.15, 15));
    Topping topping = drink.getToppingByIndex(1);
    ASSERT_EQ(topping.getName(), "Pudding");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.15);
    ASSERT_EQ(topping.getPrice(), 15);
}
TEST(drink, drink9)
{
    Drink some_drink("Black Tea", 0.3, 30);
    some_drink.addTopping(Topping ("Bubble", 0.1, 10));
    Drink drink;
    drink = some_drink; 
    Topping topping = drink.getToppingByIndex(0); 
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.4);
    ASSERT_EQ(drink.getPrice(), 40);
    ASSERT_EQ(topping.getName(), "Bubble");
}
TEST(drink, drink10)
{ 
    Drink drink("Green Tea", 0.3, 30);
    drink.addTopping(Topping ("Bubble", 0.1, 10));
    drink.addTopping(Topping ("Pudding", 0.15, 15));
    drink.addTopping(Topping ("Bubble", 0.1, 10));
    drink.addTopping(Topping ("Pudding", 0.15, 15));
    ASSERT_EQ(drink.getToppingCount(), 4);
}
