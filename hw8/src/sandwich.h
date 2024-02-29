#ifndef SANDWICH_H
#define SANDWICH_H
#include <string>


class Sandwich
{
protected:
    int Sandprice = 0;
    int SandID = 0;
    static std::set<int> record;
public:
    Sandwich() = default;
    Sandwich(int price, int id)
    {
        if (price < 0)
        {
            throw std::invalid_argument("price is error.");
        }
        Sandprice = price;
        SandID = id;
        record.insert(id);
    }
    virtual ~Sandwich()
    {
        record.erase(SandID);
    }
    int get_price()
    {
        return Sandprice;
    }
    int get_id()
    {
        return SandID;
    }
    static bool record_has_specific_id(int id)
    {
        return record.count(id);
    }
    static int get_size_of_record_container()
    {
        return record.size();
    }
};
std::set<int> Sandwich::record = std::set<int>(); //initialize the static member

#endif