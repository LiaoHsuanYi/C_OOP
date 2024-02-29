#include "../src/drink.h"

/* Place some test here */
/* TEST(GroupName, TestName){} */
TEST(drink, drink1)
{
    Drink drink("Black Tea", 0.3); 
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.3);
}
TEST(drink, drink2)
{
    Drink drink("Green Tea", 1); 
    ASSERT_EQ(drink.getName(), "Green Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 1);
}
TEST(drink, drink3)
{
    ASSERT_THROW(Drink ("Tea", 0.3), std::string);
}
TEST(drink, drink4)
{
    ASSERT_THROW(Drink ("AC", 1), std::string);
}
TEST(drink, drink5)
{
    ASSERT_THROW(Drink ("Black Tea", -0.3), std::string);
}
TEST(drink, drink6)
{
    ASSERT_THROW(Drink ("Green Tea", 1.1), std::string);
}
TEST(drink, drink7)
{ 
    Drink drink("Green Tea", 0.3);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    ASSERT_EQ(drink.getToppingCount(), 2);
}
TEST(drink, drink8)
{ 
    Drink drink("Green Tea", 0.3);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    drink.addTopping("Coconut Jelly");
    ASSERT_EQ(drink.getToppingCount(), 3);
}
TEST(drink, drink9)
{ 
    Drink drink("Green Tea", 0.3);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    ASSERT_EQ(drink.getToppingByIndex(1),"Pudding");
}
TEST(drink, drink10)
{ 
    Drink drink("Green Tea", 0.3);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    ASSERT_THROW(drink.getToppingByIndex(5),std::string);
}
TEST(drink, drink11)
{ 
    Drink drink("Green Tea", 0.3);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    ASSERT_EQ(drink.getToppingCount(), 4);
}
TEST(drink, drink12)
{ 
    Drink drink("Green Tea", 0.3);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    drink.addTopping("Coconut Jelly");
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    drink.addTopping("Coconut Jelly");
    ASSERT_EQ(drink.getToppingCount(), 6);
}