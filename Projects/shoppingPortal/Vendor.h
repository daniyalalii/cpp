#ifndef VENDOR_H
#define VENDOR_H

#include "./User.h"
#include "./inventory.h"
#include "./Order.h"
#include <vector>

class Vendor : public User
{
private:
    int vendorID;
    int salary;
    string companyName;

public:
    Vendor(int id = 0, int sal = 0, string comp = "")
    {
        vendorID = id;
        salary = sal;
        companyName = comp;
    }

    void vendorInfo() const
    {
        cout << "================ VENDOR INFO ================" << endl;
        cout << "Vendor ID: " << vendorID << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Salary: $" << salary << endl;
        cout << "=============================================" << endl;
    }
    void setVendorID(int id)
    {
        vendorID = id;
    }
    void setSalary(int sal)
    {
        salary = sal;
    }
    void increaseSalary(int newSalary)
    {
        salary += newSalary;
        cout << "Salary increased to: " << salary << endl;
    }
    void setCompanyName(string comp)
    {
        companyName = comp;
    }
    int getVendorID() const
    {
        return vendorID;
    }
    int getSalary() const
    {
        return salary;
    }
    string getCompanyName() const
    {
        return companyName;
    }
    void supplyProducts(Inventory &inventory)
    {
        cout << "Supplying products..." << endl;
        cout << "Enter product details to supply:" << endl;
        inventory.addProduct();
    }
    void respondtoRequests(Order &order)
    {
        cout << "Responding to requests..." << endl;
        // Logic to respond to requests
        // For example, checking for pending requests and fulfilling them
        order.displayOrder();
        // Fulfill the order
        order.fulfillOrder();
    }

    void vendorResponse()
    {
        extern Inventory inventory;
        Order order(1, Customer(), {}, 0.0);
        cout << "Enter your choice: " << endl;
        cout << "0. Exit vendor menu" << endl;
        cout << "1. Supply products" << endl;
        cout << "2. Respond to requests" << endl;
        cout << "3. Display order details" << endl;
        cout << "4. Display vendor info" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Supply products
            supplyProducts(inventory);
            break;
        case 2:
            // Respond to requests
            respondtoRequests(order);
            break;
        case 3:
            // Display order details
            order.displayOrder();
            break;
        case 4:
            // Display vendor info
            vendorInfo();
            break;
        case 0:
            cout << "Exiting vendor menu." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
};

#endif