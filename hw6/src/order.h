#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "alcohol.h"
#include "algorithm.h"

class Order{
public:
    std::vector<Alcohol *> alcohol;
    int AlcoholCount = 0;
    int TotalPrice = 0;

    Order() = default;

    void append_alcohol(Alcohol* alcohol){
        this -> alcohol.push_back(alcohol);
        AlcoholCount += 1;
        TotalPrice += alcohol->get_price();
    }

    int get_alcohol_count(){
        return AlcoholCount;
    }

    int get_total_price(){
        return TotalPrice;
    }
};


#endif