#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H
#include "cake.h"
#include <string>

class GeodeCake : public Cake
{
protected:
    static int GeodeCount;
public:
    GeodeCake() = default;
    GeodeCake(int price, int sweet) : Cake(price, sweet){GeodeCount += 1;};
    virtual ~GeodeCake()
    {
        GeodeCount -= 1;
    }
    std::string to_string()
    {
        char buf[128];
        sprintf(buf, "| %-20s | %10d | %10d |", "GeodeCake", CakePrice, CakeSweet);
        return buf;
    }
    static int get_count()
    {
        return GeodeCount;
    }
};
int GeodeCake::GeodeCount = 0;

#endif