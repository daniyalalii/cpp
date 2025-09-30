#ifndef REPORT_H
#define REPORT_H
#include "Invoice.h"
#include "Order.h"
#include "inventory.h"

class Report
{
public:
    void generateSalesReport(const vector<Order>& orders)
    {
        cout << "Generating Sales Report..." << endl;
        cout << "Total Sales Orders: " << orders.size() << endl;
        double totalSales = 0.0;
        for (const auto& order : orders)
        {
            totalSales += order.getTotalAmount();
        }
        cout << "Total Sales Amount: $" << totalSales << endl;
    }

    void generateInventoryReport(const Inventory& inventory)
    {
        cout << "Generating Inventory Report..." << endl;
        inventory.displayInventory();
    }

    void generatePurchaseReport(const vector<Order>& orders)
    {
        cout << "Generating Purchase Report..." << endl;
        cout << "Total Purchase Orders: " << orders.size() << endl;
        double totalPurchases = 0.0;
        for (const auto& order : orders)
        {
            totalPurchases += order.getTotalAmount();
        }
        cout << "Total Purchase Amount: $" << totalPurchases << endl;
    }
    
};


#endif