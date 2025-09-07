#ifndef ORDER_H
#define ORDER_H
#include "inventory.h"

class order
{
private:
    vector<item *> orderItems;
    double preTax;
    double tax;
    double totalPrice;
    string paymentMethod;
    bool status; // instead of string we used bool for pending/complete orders;
public:
    order() : preTax(0), tax(0), totalPrice(0), paymentMethod(""), status(false) {}

    void addItemInOrder(item *itm, int quantity, string payMethod)
    {
        item *orderItem = new item(itm->getName(), itm->getBarcode(), itm->getPrice(), quantity);
        orderItems.push_back(orderItem);
        preTax += itm->getPrice() * quantity;
        if (payMethod == "Cash")
        {
            tax = preTax * 0.15;
        }
        else if (payMethod == "Card")
        {
            tax = preTax * 0.05;
        }
        else
        {
            tax = preTax * 0.10;
        }
        totalPrice = preTax + tax;
    }


    void removeItemFromOrder(const string &barcode)
    {
        for (auto it = orderItems.begin(); it != orderItems.end(); ++it)
        {
            if ((*it)->getBarcode() == barcode)
            {
                preTax -= (*it)->getPrice() * (*it)->getQuantity();
                tax = preTax * 0.1;
                totalPrice = preTax + tax;
                delete *it;
                orderItems.erase(it);
                cout << "Item removed from order.\n";
                return;
            }
        }
        cout << "Item not found in order.\n";
    }

    void printOrderDetails() const
    {
        cout << "\n--- Order Details ---\n";
        for (const auto &itm : orderItems)
        {
            itm->printItemDetails();
            cout << "------------------------\n";
        }
        cout << "Pre-Tax Amount: " << preTax << endl;
        cout << "Tax: " << tax << endl;
        cout << "Total Price: " << totalPrice << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Order Status: " << (status ? "Complete" : "Pending") << endl;
    }

    void completeOrder()
    {
        status = true;
        cout << "Order marked as complete.\n";
    }
    void generateBill() const
    {
        cout << "\n--- Bill ---\n";
        for (const auto &itm : orderItems)
        {
            cout << itm->getName() << " x" << itm->getQuantity() << " @ " << itm->getPrice() << " each = " << itm->getPrice() * itm->getQuantity() << endl;
        }
        cout << "Pre-Tax Amount: " << preTax << endl;
        cout << "Tax: " << tax << endl;
        cout << "Total Price: " << totalPrice << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "------------------------\n";
    }

    order operator += (const order &other)
    {
        for (const auto &itm : other.orderItems)
        {
            orderItems.push_back(new item(*itm));
        }
        preTax += other.preTax;
        tax += other.tax;
        totalPrice += other.totalPrice;
        paymentMethod = other.paymentMethod;
        status = other.status;
        return *this;
    }

    order operator -= (const order &other)
    {
        for (const auto &itm : other.orderItems)
        {
            removeItemFromOrder(itm->getBarcode());
        }
        preTax -= other.preTax;
        tax -= other.tax;
        totalPrice -= other.totalPrice;
        return *this;
    }

    ~order()
    {
        for (auto itm : orderItems)
        {
            delete itm;
        }
        cout << "Order destroyed.\n";
    }
};
#endif