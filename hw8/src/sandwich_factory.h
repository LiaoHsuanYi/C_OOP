#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H
#include <vector>
#include <string>


template <typename T>
class SandwichFactory
{
public:
    SandwichFactory() = default;
    ~SandwichFactory() = default;
    static T* create_sandwich(int price, int id)
    {
        return new T(price, id);
    }
    static std::vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list)
    {
        if(count < 0)
        {
            throw std::invalid_argument("count is error.");
        }
        std::vector<T*> sandwich;
        for (int i = 0; i < count; i++)
        {
            sandwich.push_back(new T(price, id_list[i]));
        }
        return sandwich;
    }
};



#endif