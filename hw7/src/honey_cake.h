#ifndef HONEY_CAKE_H
#define HONEY_CAKE_H
#include "cake.h"
#include <string>

class HoneyCake : public Cake
{
protected:
    static int HoneyCount;
public:
    HoneyCake() = default;
    HoneyCake(int price, int sweet) : Cake(price, sweet){HoneyCount += 1;};
    virtual ~HoneyCake()
    {
        HoneyCount -= 1;
    }
    std::string to_string()
    {
        char buf[128];
        sprintf(buf, "| %-20s | %10d | %10d |", "HoneyCake", CakePrice, CakeSweet);
        return buf;
    }
    static int get_count()
    {
        return HoneyCount;
    }
};
int HoneyCake::HoneyCount = 0;

#endif