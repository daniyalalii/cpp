#ifndef ORDER_H
#define ORDER_H

#include "./Cart.h"
#include "./Customer.h"
#include "./Item.h"
using namespace std;

enum class OrderStatus { Pending, Shipped, Delivered, Cancelled };

class Order
{
private:
    int orderID;
    Customer customer;
    vector<Cart> items;
    double totalAmount;
    OrderStatus status;

public:
    Order(int orderID, const Customer& customer, const vector<Cart>& items, double totalAmount)
        : orderID(orderID), customer(customer), items(items), totalAmount(totalAmount), status(OrderStatus::Pending) {}

    void updateStatus(OrderStatus newStatus)
    {
        status = newStatus;
    }

    void displayOrder()
    {
        cout << "=========== ORDER DETAILS ===========\n";
        cout << "Order ID: " << orderID << endl;
        customer.displayCustomerInfo();
        cout << "--------------------------------------\n";
        cout << "Items:\n";
        for (const auto& item : items)
        {
            item.printItemsDescription();
        }
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Status: ";
        switch (status)
        {
            case OrderStatus::Pending: cout << "Pending"; break;
            case OrderStatus::Shipped: cout << "Shipped"; break;
            case OrderStatus::Delivered: cout << "Delivered"; break;
            case OrderStatus::Cancelled: cout << "Cancelled"; break;
        }
        cout << endl;
    }
    void fulfillOrder()
    {
        if (status == OrderStatus::Pending)
        {
            updateStatus(OrderStatus::Shipped);
            cout << "Order " << orderID << " has been shipped." << endl;
            totalAmount *= 1.05; // Adding a 5% shipping fee
        }
        else
        {
            cout << "Order cannot be fulfilled. Current status: ";
            switch (status)
            {
                case OrderStatus::Shipped: cout << "Shipped"; break;
                case OrderStatus::Delivered: cout << "Delivered"; break;
                case OrderStatus::Cancelled: cout << "Cancelled"; break;
                default: break;
            }
            cout << endl;
        }
    }
    int getOrderID() const
    {
        return orderID;
    }
    double getTotalAmount() const
    {
        return totalAmount;
    }
};

#endif