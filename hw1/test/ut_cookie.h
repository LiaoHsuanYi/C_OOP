#include <gtest/gtest.h>
#include "../src/cookie.h"
// A single test case has the following form:
//
// TEST(TestSuiteName, TestName) {
//   ... test body ...
// }
TEST(COOKIE, max_dv1)
{
    int dim = 4;
    int arr[4]={1, 3, 5, 7};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, 10);
}
TEST(COOKIE, max_dv2)
{
    int dim = 4;
    int arr[4]={4, 3, 2, 1};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, 6);
}
TEST(COOKIE, max_dv3)
{
    int dim = 3;
    int arr[3]={5, 2, 3};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, 8);
}
TEST(COOKIE, max_dv4)
{
    int dim = 3;
    int arr[3]={4, 3, 7};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, 11);
}
TEST(COOKIE, max_dv5)
{
    int dim = 4;
    int arr[4]={1, -2, 3, 4};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, -1);
}
TEST(COOKIE, max_dv6)
{
    int dim = 4;
    int arr[4]={4, 3, -5, 6};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, -1);
}
TEST(COOKIE, max_dv7)
{
    int dim = -4;
    int arr[4]={5, 2, 3, 4};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, -1);
}
TEST(COOKIE, max_dv8)
{
    int dim = -4;
    int arr[4]={4, 3, 7, 2};
    int output = max_dv(dim, arr);
    ASSERT_EQ(output, -1);
}