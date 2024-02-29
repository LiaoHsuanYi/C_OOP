#ifndef CAKE_H
#define CAKE_H
#include <string>

class Cake{
protected:
    int CakePrice = 0;
    int CakeSweet = 0;
    static int CakeTotal;
public:
    Cake() = default;
    Cake(int price, int sweet)
    {
        CakePrice = price;
        CakeSweet = sweet;
        CakeTotal += 1;
    }

    virtual ~Cake()
    {
        CakeTotal -= 1;
    }
    
    int get_price()
    {
        return CakePrice;
    }

    int get_sweet()
    {
        return CakeSweet;
    }

    static int get_total()
    {
        return CakeTotal;
    }

    virtual std::string to_string() = 0;
};
int Cake::CakeTotal = 0; //initialize the static member

#endif