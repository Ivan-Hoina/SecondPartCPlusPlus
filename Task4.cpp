#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
public:
    ShopItemOrder(string name, float cost, int amount)
    {
        setItemName(name);
        setItemCost(cost);
        setItemsAmount(amount);
    }

    void setItemName(string name)
    {
        itemName = name;
    }

    void setItemCost(float cost)
    {
        itemCost = cost;
        if (itemCost < 0)
            itemCost = 0;
    }

    void setItemsAmount(int amount)
    {
        itemsAmount = amount;

        if (amount < 0)
            itemsAmount = 0;
    }

    string getItemName()
    {
        return itemName;
    }

    float getItemCost()
    {
        return itemCost;
    }

    int getItemsAmount()
    {
        return itemsAmount;
    }

    float getTotalCost()
    {
        return itemCost * itemsAmount;
    }

    void toString()
    {
        cout << "Item: " << itemName <<
            "\nCost per Item: " << itemCost <<
            "\nItems Amount: " << itemsAmount <<
            "\nTotal cost: " << itemCost * itemsAmount << '\n';
    }

private:
    string itemName;
    float itemCost;
    int itemsAmount;
};