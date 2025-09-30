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
    void supplyProducts(Inventory& inventory)
    {
        cout << "Supplying products..." << endl;
        cout<<"Enter product details to supply:"<<endl;
        inventory.addProduct();
    }
    void respondtoRequests(Order &order){
        cout << "Responding to requests..." << endl;
        // Logic to respond to requests
        // For example, checking for pending requests and fulfilling them
        order.displayOrder();
        // Fulfill the order
        order.fulfillOrder();
    }
};

#endif