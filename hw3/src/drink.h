#include <string>
#include <vector>

class Drink{
private:
    /* Put some attribute on here if necessary. */
    std::string DrinkName;
    double DrinkSweetnessLevel;
    std::vector<std::string> DrinkTopping;
    int DrinkCount;
public:
    Drink() //default constructer
    {
        DrinkName = "";
        DrinkSweetnessLevel = -1;
        DrinkCount = 0;
    }
    /* The constructor of the Drink. */
    Drink(std::string name, double sweetness_level)
    {
        if (name.length() < 4)
        {
            throw std::string("name is error");
        }
        if (sweetness_level < 0 || sweetness_level > 1)
        {
            throw std::string("Sweetness level is error");
        }
        DrinkCount = 0;
        DrinkName = name;
        DrinkSweetnessLevel = sweetness_level;
    }
    /* The destructor of the Drink. */
    ~Drink() = default;
    /* Return the name of drink. */
    std::string getName()
    {
        if (DrinkName == "")
        {
            throw std::string("name is empty");
        }
        return DrinkName;
    }
    /* Return the level of sweetness. */
    double getSweetnessLevel()
    {
        if (DrinkSweetnessLevel == -1)
        {
            throw std::string("Sweetness level isn't setting");
        }
        return DrinkSweetnessLevel;
    }
    /* Add a topping to the drink. */
    void addTopping(std::string topping)
    {
        DrinkTopping.push_back(topping);
        DrinkCount += 1;
    }    
    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    std::string getToppingByIndex(int index)
    {
        if (index < 0 || DrinkTopping.size() <= index)
        {
            throw std::string("Out of Range");
        }
        return DrinkTopping[index];
    }
    /* Get the count of topping in drink. */
    int getToppingCount()
    {
        return DrinkCount;
    }

};