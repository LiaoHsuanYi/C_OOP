#ifndef ALCOHOL_H
#define ALCOHOL_H
#include <string>
#include <stdexcept>

class Alcohol{
protected:
    std::string AlcoholName = "";
    int AlcoholPrice = 0;
    double AlcoholContent = 0;

public:
    Alcohol() = default;
    Alcohol(std::string name, int price, double content)
    {
        if (name.length() == 0)
        {
            throw std::invalid_argument("name is error");
        }
        if (content < 0 || content > 1)
        {
            throw std::invalid_argument("Alcohol Content is error");
        }
        if(price <= 0)
        {
            throw std::invalid_argument("Price isn't exist");
        }
        AlcoholName = name;
        AlcoholPrice = price;
        AlcoholContent = content;
    }
    virtual ~Alcohol() {};
    virtual void dilute() = 0;
    double get_alcohol_content(){
        return AlcoholContent;
    }
    int get_price(){
       return AlcoholPrice;
    }
    std::string get_name(){
       return AlcoholName;
    }

};


#endif