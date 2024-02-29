#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H
#include "sandwich.h"

class BeefSandwich : public Sandwich
{
protected:
    static std::set<int> record;
public:
    BeefSandwich() = default;
    BeefSandwich(int price, int id): Sandwich(price, id){record.insert(id);};
    ~BeefSandwich()
    {
        record.erase(SandID);
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
std::set<int> BeefSandwich::record = std::set<int>();





#endif