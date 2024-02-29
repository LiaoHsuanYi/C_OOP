#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <string>
#include <vector>
#include "Product.h"

class ShoppingCart{
private:
    std::vector<Product> ItemList;

    bool isIndexOutOfItemListRange(int index) const{
        return !(index < ItemList.size());
    }
    
    bool isProductListHasDuplicateItem(int productList_size, Product* productList){
        for(int i = 0; i < productList_size; i++){
            for(int j = 0; j < productList_size; j++){
                if (productList[i] == productList[j]) return true;
            }
        }
        return false;
    }

    bool isProductAlreadyExistInItemList(Product product){
        for(int i = 0; i < ItemList.size(); i++){
            if(ItemList[i] == product){
                return true;
            }
        }
        return false;
    }

    ShoppingCart doUnionOfTwoShoppingCart(ShoppingCart sc1, ShoppingCart sc2) const{
        for (int i = 0; i < sc2.ItemList.size(); i++)
        {
            if(sc1.isProductAlreadyExistInItemList(sc2.ItemList[i])){
                continue;
            }
            sc1.appendItem(sc2.ItemList[i]);
        }
        return sc1;
    }
    ShoppingCart doDifferenceOfTwoShoppingCart(ShoppingCart sc1, ShoppingCart sc2) const{
        std::vector<Product> productList;
        for (int i = 0; i < sc1.ItemList.size(); i++)
        {
            if(sc2.isProductAlreadyExistInItemList(sc1.ItemList[i])){
                continue;
            }
            productList.push_back(sc1.ItemList[i]);
        }
        sc1.ItemList = productList;
        return sc1;
    }



public:
    ShoppingCart() = default;
    
    ShoppingCart(int item_list_size, Product* item_list)
    {
        if(isProductListHasDuplicateItem(item_list_size, item_list)){
            throw std::string("Duplicate item happen.");
        }
        ItemList = std::vector<Product>(item_list, item_list + item_list_size);
    }

    int getItemCount() const
    {
        return ItemList.size();
    }

    Product getItemByIndex(int index) const
    {
        if (isIndexOutOfItemListRange(index)){
            throw std::string("Out of the range of item list.");
        }
        return ItemList[index];
    }

    void setItemByIndex(int index, Product product)
    {
        if(isIndexOutOfItemListRange(index)){
            throw std::string("Out of the range of item list.");
        }
        if(!(ItemList[index] == product) && isProductAlreadyExistInItemList(product)){
            throw std::string("Duplicate item happen.");
        }
        ItemList[index] = product;
        
    }

    void appendItem(Product product)
    {
        if(isProductAlreadyExistInItemList(product)){
            throw std::string("Duplicate item happen.");
        }
        ItemList.push_back(product);

    }

    int getTotalCost() const
    {
        int total = 0;
        for (int i = 0; i < ItemList.size(); i++)
        {
            total += ItemList[i].getPrice();
        }
        return total;
    }

    ShoppingCart& operator+(const ShoppingCart &other)
    {
        *this = doDifferenceOfTwoShoppingCart(*this, other);
        return *this;
    }

    ShoppingCart& operator-(const ShoppingCart &other)
    {
        *this = doUnionOfTwoShoppingCart(*this, other);
        return *this;
    }

    ShoppingCart& operator=(const ShoppingCart &other)
    {
        if (this != &other){
            ItemList = other.ItemList;
        }
        return *this;
    }
};
#endif