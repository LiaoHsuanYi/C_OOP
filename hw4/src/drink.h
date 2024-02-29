#include <string>
#include <vector>
#include "topping.h"
#ifndef DRINK_H
#define DRINK_H

class Drink{
private:
    /* Put some attribute on here if necessary. */
    std::string DrinkName;
    double DrinkSweetnessLevel;
    std::vector<Topping> DrinkTopping;
    int DrinkCount;
    int DrinkPrice;

public:

	Drink()
    {
        DrinkName = "";
        DrinkSweetnessLevel = -1;
        DrinkCount = 0;
        DrinkPrice = -1;
    }
   
	/* The constructor of the Drink. */
	Drink(std::string name, double sweetness_level, int price)
    {
        if (name.length() < 4)
        {
            throw std::string("name is error");
        }
        if (sweetness_level < 0 || sweetness_level > 1)
        {
            throw std::string("Sweetness level is error");
        }
        if(price <= 0)
        {
            throw std::string("Drink price isn't exist");
        }
        DrinkName = name;
        DrinkSweetnessLevel = sweetness_level;
        DrinkPrice = price;
        DrinkCount = 0;
    }

	/* The destructor of the Drink. */
	~Drink() = default;

	/* Return the name of drink. */
	std::string getName() 
    {
        return DrinkName;
    }

	/* Return the level of sweetness. */
	double getSweetnessLevel()
    {
        return DrinkSweetnessLevel;
    }

	/* Return the price of drink. */
	int getPrice() 
    {
        return DrinkPrice;
    }

	/* Add a topping to the drink. */
	void addTopping(Topping topping)
    {
        DrinkTopping.push_back(topping);
        DrinkCount += 1;
        DrinkSweetnessLevel += topping.getSweetnessLevel();
        DrinkPrice += topping.getPrice();
    }

	/* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
	Topping getToppingByIndex(int index) const
    {
        if (index < 0 || DrinkCount <= index)
        {
            throw std::string("Out of Range");
        }
        return DrinkTopping[index];
    }

	/* Get the count of topping in drink. */
	int getToppingCount() const
    {
        return DrinkCount;
    }

	/* Operator overloading */
	Drink &operator=(const Drink& other)
    {
        if (this != &other)
        {
            std::cout << "copy assignment" << std::endl;
            DrinkName = other.DrinkName;
            DrinkSweetnessLevel = other.DrinkSweetnessLevel;
            DrinkPrice = other.DrinkPrice;
            if(other.DrinkCount > 0)
            {
                for (int i = 0; i < other.DrinkCount; i++)
                {
                    this -> DrinkTopping.push_back(other.DrinkTopping[i]);
                    this -> DrinkCount = other.DrinkCount;
                }
            }
            
        }
        
        return *this;
    }


};

#endif