#include <gtest/gtest.h>
#include "../src/HelloWorld.h"

TEST(HelloWorld, Print)
{
    std:: string compare = "Hello World! ";
    std:: string output = Print();
    ASSERT_EQ(compare, output);
}