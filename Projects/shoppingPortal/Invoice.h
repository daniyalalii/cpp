#ifndef INVOICE_H
#define INVOICE_H
#include "Cart.h"
#include "Order.h"

class Invoice
{
    private:
    int invoiceID;
    double totalAmount;
    vector<Cart> items;
    public:
    Invoice(int id = 0, double amount = 0.0, const vector<Cart>& items = {})
    {
        invoiceID = id;
        totalAmount = amount;
        this->items = items;
    }
    virtual void generateInvoice() = 0;
    void displayInvoice()
    {
        cout << "=========== INVOICE ===========\n";
        cout << "Invoice ID: " << invoiceID << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Items:\n";
        for (const auto& item : items)
        {
            item.printItemsDescription();
        }
        cout << "===============================\n";
    }
    int getInvoiceID() const
    {
        return invoiceID;
    }
    double getTotalAmount() const
    {
        return totalAmount;
    }
};

class SaleInvoice : public Invoice
{
    public:
    SaleInvoice(int id = 0, int amount = 0, const vector<Cart>& items = {}) : Invoice(id, amount, items) {}
    void generateInvoice() override
    {
        cout << "Generating Sale Invoice..." << endl;
        // Logic to generate sale invoice
        displayInvoice();
    }
};

class PurchaseInvoice : public Invoice
{
    private:
    bool type;
    // true for credit, false for cash
    public:
    PurchaseInvoice(int id = 0, int amount = 0, const vector<Cart>& items = {}, bool type = false) : Invoice(id, amount, items), type(type) {}
    void setType(bool t)
    {
        type = t;
    }
    bool getType() const
    {
        return type;
    }
    
    void generateInvoice() override
    {
        cout << "Generating Purchase Invoice..." << endl;
        // Logic to generate purchase invoice
        displayInvoice();
    }
};

#endif