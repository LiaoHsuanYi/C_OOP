#include <gtest/gtest.h>
#include "../src/sandwich.h"
#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
#include "../src/sweet_sandwich.h"


TEST(sandwich, sandwich1)
{
    Sandwich *bf1 = new BeefSandwich(25, 0);
    Sandwich *sw1 = new SweetSandwich(15, 1);
    Sandwich *bf2 = new BeefSandwich(45, 2);
    Sandwich *sw2 = new SweetSandwich(25, 3);

    ASSERT_THROW(Sandwich(-10, 30), std::invalid_argument);

    ASSERT_TRUE(BeefSandwich::record_has_specific_id(0)); 
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(1)); 
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); 
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); 
    ASSERT_TRUE(Sandwich::record_has_specific_id(0)); 
    ASSERT_TRUE(Sandwich::record_has_specific_id(1)); 
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); 
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); 

    ASSERT_EQ(2, BeefSandwich::get_size_of_record_container()); 
    ASSERT_EQ(2, SweetSandwich::get_size_of_record_container()); 
    ASSERT_EQ(4, Sandwich::get_size_of_record_container()); 

    delete sw1;
    delete bf1;

    ASSERT_FALSE(BeefSandwich::record_has_specific_id(0)); 
    ASSERT_FALSE(SweetSandwich::record_has_specific_id(1)); 
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); 
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); 
    ASSERT_FALSE(Sandwich::record_has_specific_id(0)); 
    ASSERT_FALSE(Sandwich::record_has_specific_id(1)); 
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); 
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); 

    ASSERT_EQ(1, BeefSandwich::get_size_of_record_container()); 
    ASSERT_EQ(1, SweetSandwich::get_size_of_record_container()); 
    ASSERT_EQ(2, Sandwich::get_size_of_record_container()); 

    delete sw2;
    delete bf2;

}