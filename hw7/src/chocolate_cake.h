#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H
#include "cake.h"
#include <string>

class ChocolateCake : public Cake
{
protected:
    static int ChocoCount;
public:
    ChocolateCake() = default;
    ChocolateCake(int price, int sweet) : Cake(price, sweet){ChocoCount += 1;}
    virtual ~ChocolateCake()
    {
        ChocoCount -= 1;
    }
    std::string to_string()
    {
        char buf[128];
        sprintf(buf, "| %-20s | %10d | %10d |", "ChocolateCake", CakePrice, CakeSweet);
        return buf;
    }
    static int get_count()
    {
        return ChocoCount;
    }
};
int ChocolateCake::ChocoCount = 0;

#endif