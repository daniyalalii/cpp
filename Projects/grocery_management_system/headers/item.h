#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class item
{
private:
    string name;
    string barcode;
    double price;
    int quantity;

public:
    item(string n, string bar, double p, int q)
    {
        name = n;
        barcode = bar;
        price = p;
        quantity = q;
    }
    void changeItemName(string newName)
    {
        name = newName;
    }
    void changeItemPrice(double newPrice)
    {
        price = newPrice;
    }
    void addQuantity(int qty)
    {
        quantity += quantity;
    }
    void printItemDetails() const
    {
        cout << "Item Name: " << name << endl;
        cout << "Barcode: " << barcode << endl;
        cout << "Item Price: " << price << endl;
        cout << "Quantity in hands: " << quantity << endl;
    }
    bool operator==(item &other)
    {
        bool result = false;
        if (barcode == other.barcode)
        {
            result = true;
        }
        return result;
    }
    item operator+(item &other)
    {
        quantity += other.quantity;
    }
    ~item()
    {
        cout << "Distructor called" << endl;
    }
};
#endif
