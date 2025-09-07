#include "item.h"
#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>

class inventory
{
private:
    vector<item *> items;

public:
    inventory() {}
    void addItem(const string &name, const string &barcode, double price, int quantity)
    {
        item *newItem = new item(name, barcode, price, quantity);
        items.push_back(newItem);
    }

    void addItem(const item &itm)
    {
        item *newItem = new item(itm);
        items.push_back(newItem);
    }
    
    item *findItem(const string &barcode)
    {
        for (auto item : items)
        {
            if (item->getBarcode() == barcode)
            {
                return item;
            }
        }
        return nullptr;
    }

    void removeItem(const string &barcode)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if ((*it)->getBarcode() == barcode)
            {
                delete *it;
                items.erase(it);
                cout << "Item removed from inventory.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void printAllItems() const
    {
        cout << "\n--- Inventory Items ---\n";
        for (auto item : items)
        {
            item->printItemDetails();
            cout << "------------------------\n";
        }
    }

    ~inventory()
    {
        for (auto item : items)
        {
            delete item;
        }
        cout << "Inventory destroyed.\n";
    }
};

#endif
