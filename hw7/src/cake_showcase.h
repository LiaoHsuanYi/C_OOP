#ifndef CAKE_SHOWCASE_H
#define CAKE_SHOWCASE_H
#include <string>
#include <vector>

template <typename T>
class CakeShowcase
{
protected:
    std::vector<T *> cake;

public:
    CakeShowcase() = default;
    CakeShowcase(int length, T** array)
    {
        for (int i = 0; i < length; i++)
        {
            cake.push_back(array[i]);
        }
    }
    ~CakeShowcase() = default;
    int calc_total_price()
    {
        int TotalPrice = 0;
        for (int i = 0; i < cake.size(); i++)
        {
            TotalPrice += cake[i]->get_price();
        }
        return TotalPrice;
    }
    int calc_total_sweet()
    {
        int TotalSweet = 0;
        for (int i = 0; i < cake.size(); i++)
        {
            TotalSweet += cake[i]->get_sweet();
        }
        return TotalSweet;
    }
    std::string to_string()
    {   
        std::string buf = "";
        buf += "| CakeName             | Price      | Sweet      |\n";
        buf += "| -------------------- | ---------- | ---------- |\n";
        for (int i = 0; i < cake.size(); i++)
        {
            buf += cake[i]->to_string() + "\n";
        }
        buf += "| -------------------- | ---------- | ---------- |";
        return buf;
    }
    T* operator[](int index)
    {
        if (index < 0 || cake.size() <= index)
        {
            throw std::out_of_range("Out of Range");
        }
        return cake[index];
    }
};

#endif