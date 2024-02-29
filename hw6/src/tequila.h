#ifndef TEQUILA_H
#define TEQUILA_H
#include <string>
#include <stdexcept>
#include "alcohol.h"

class Tequila : public Alcohol
{
public:
    Tequila() = default;
    Tequila(std::string name, int price, double content): Alcohol(name, price, content){}
    ~Tequila() = default;

    void dilute(){
        AlcoholContent *= 0.95;
    }
    Tequila operator+(const Tequila &other){
        std::string Names = AlcoholName;
        double Contents = (AlcoholContent + other.AlcoholContent)/2;
        int Prices = AlcoholPrice + other.AlcoholPrice;
        Tequila sum(Names, Prices, Contents);
        return sum;
    }
    bool operator==(const Tequila &other){
        if (AlcoholName == other.AlcoholName && AlcoholContent == other.AlcoholContent && AlcoholPrice == other.AlcoholPrice)
        {
            return true;
        }
        return false;
    }
    Tequila &operator=(const Tequila &other){
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