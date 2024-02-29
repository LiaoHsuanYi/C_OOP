#ifndef SOUR_H
#define SOUR_H
#include <string>
#include <stdexcept>
#include "alcohol.h"

class Sour : public Alcohol
{
public:
    Sour() = default;
    Sour(std::string name, int price, double content) : Alcohol(name, price, content){}
    ~Sour() = default;
    void dilute(){
        AlcoholContent *= 0.7;
    }
    Sour operator+(const Sour &other){
        std::string Names = AlcoholName;
        double Contents = (AlcoholContent + other.AlcoholContent)/2;
        int Prices = AlcoholPrice + other.AlcoholPrice;
        Sour sum(Names, Prices, Contents);
        return sum;
    }
    bool operator==(const Sour &other){
        if (AlcoholName == other.AlcoholName && AlcoholContent == other.AlcoholContent && AlcoholPrice == other.AlcoholPrice)
        {
            return true;
        }
        return false;
    }
    Sour &operator=(const Sour &other){
       if (this != &other)
       {
        std::cout << "copy assignment" << std::endl;
        AlcoholName = other.AlcoholName;
        AlcoholPrice = other.AlcoholPrice;
        AlcoholContent = other.AlcoholContent;
       }
       return *this;
    }


};


#endif