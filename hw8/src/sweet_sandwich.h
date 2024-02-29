#ifndef SWEET_SANDWICH_H
#define SWEET_SANDWICH_H
#include "sandwich.h"

class SweetSandwich : public Sandwich
{
protected:
    static std::set<int> record;
public:
    SweetSandwich() = default;
    SweetSandwich(int price, int id) : Sandwich(price, id){record.insert(id);};
    ~SweetSandwich()
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
std::set<int> SweetSandwich::record = std::set<int>(); 




#endif