#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>


class Product{
private:
    std::string ProductName;
    int ProductPrice;

public:
    Product() // default constructor
    {
        ProductPrice = -1;
        ProductName = "";
    }

    void init(std::string name, int price)
    {
        if (name.length() < 4)
        {
            throw std::string("name is error");
        }
        if (price <= 0)
        {
            throw std::string("Product price isn't exist");
        }
        ProductName = name;
        ProductPrice = price;
    } 

    Product(std::string name, int price)
    {   
        init(name, price);
    }   

    ~Product() = default;

    std::string getName() const
    {
        return ProductName;
    }

    int getPrice() const
    {
        return ProductPrice;
    }

    Product& operator=(const Product& other)
    {
        if (this!= &other)
        {
            init(other.getName(), other.getPrice());
        }
        return *this;
    }

    bool operator==(const Product& other)
    {
        return this -> ProductName == other.getName();
    }
};
#endif