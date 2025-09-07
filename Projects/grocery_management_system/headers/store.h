#ifndef STORE_H
#define STORE_H
#include "order.h"
class store
{
private:
    inventory storeInventory;
    vector<order> pendingOrders;
    vector<order> completedOrders;
    double totalRevenue;

public:
    store() : totalRevenue(0) {}

    void createOrder(const order &newOrder)
    {
        pendingOrders.push_back(newOrder);
        cout << "New order created and added to pending orders.\n";
    }
    void removeOrder(int orderIndex)
    {
        if (orderIndex < 0 || orderIndex >= pendingOrders.size())
        {
            cout << "Invalid order index.\n";
            return;
        }
        pendingOrders.erase(pendingOrders.begin() + orderIndex);
        cout << "Order removed from pending orders.\n";
    }
    void printSortedOrders() const
    {
        cout << "\n--- Pending Orders ---\n";
        for (const auto &ord : pendingOrders)
        {
            ord.printOrderDetails();
            cout << "------------------------\n";
        }
    }
    void completeOrder(int orderIndex)
    {
        if (orderIndex < 0 || orderIndex >= pendingOrders.size())
        {
            cout << "Invalid order index.\n";
            return;
        }
        pendingOrders[orderIndex].completeOrder();
        totalRevenue += pendingOrders[orderIndex].getTotalPrice();
        completedOrders.push_back(pendingOrders[orderIndex]);
        pendingOrders.erase(pendingOrders.begin() + orderIndex);
        cout << "Order completed and moved to completed orders.\n";
    }
    void addPendingOrder(const order &newOrder)
    {
        pendingOrders.push_back(newOrder);
        cout << "New order added to pending orders.\n";
    }
    void modifyPendingOrder(int orderIndex)
    {
        if (orderIndex < 0 || orderIndex >= pendingOrders.size())
        {
            cout << "Invalid order index.\n";
            return;
        }
        pendingOrders[orderIndex].printOrderDetails();
        string barcode;
        cout << "Enter item barcode to remove from order: ";
        cin >> barcode;
        pendingOrders[orderIndex].removeItemFromOrder(barcode);
        cout << "Item removed from order if it existed.\n";
    }

    void calculateRevenue() const
    {
        cout << "Total Revenue: " << totalRevenue << endl;
    }

    void displayCompletedOrders() const
    {
        cout << "\n--- Completed Orders ---\n";
        for (const auto &ord : completedOrders)
        {
            ord.printOrderDetails();
            cout << "------------------------\n";
        }
    }
    void displayPendingOrdersSorted() const
    {
        cout << "\n--- Pending Orders (Sorted) ---\n";
        for (const auto &ord : pendingOrders)
        {
            ord.printOrderDetails();
            cout << "------------------------\n";
        }
    }
    ~store()
    {
        cout << "Store destroyed.\n";
    }
};

#endif