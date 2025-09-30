#ifndef MANAGER_H
#define MANAGER_H

#include "./User.h"
#include "./inventory.h"
#include "./Order.h"
#include <vector>

class Manager : public User
{
public:
    void viewInventory(const Inventory &inventory)
    {
        cout << "Viewing inventory..." << endl;
        inventory.displayInventory();
    }

    // Manage orders (e.g., view, update, delete orders)
    void manageOrders(Inventory &inventory, vector<Order> &orders)
    {
        cout << "Enter your choice: " << endl;
        cout << "1. View all orders" << endl;
        cout << "2. Update stocks" << endl;
        cout << "3. Delete an order" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Viewing all orders..." << endl;
            for (auto &order : orders)
            {
                order.displayOrder();
            }
            break;

        case 2:
            cout << "Updating stocks..." << endl;
            // Logic to update order status
            int sku;
            cout << "Enter SKU of the product to update: ";
            cin >> sku;
            inventory.updateQuantity(sku);
            break;

        case 3:
            cout << "Deleting an order..." << endl;
            // Logic to delete an order
            int orderId;
            cout << "Enter Order ID to delete: ";
            cin >> orderId;
            orders.erase(remove_if(orders.begin(), orders.end(),
                                   [orderId](const Order &order)
                                   { return order.getOrderID() == orderId; }),
                         orders.end());
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    void respondtoRequests(Order &order){
        cout << "Responding to requests..." << endl;
        // Logic to respond to requests
        // For example, checking for pending requests and fulfilling them
        order.displayOrder();
        order.fulfillOrder();
    }
};

#endif