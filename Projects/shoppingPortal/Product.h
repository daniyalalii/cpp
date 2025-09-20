#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int SKU;
    string name;
    string description;
    double salePrice;
    double purchasePrice;
    int stockQuantity;
    string category;
    string department;

public:
    Product(int sku = 0, string name = "", string desc = "", double sPrice = 0.0, double pPrice = 0.0, int quantity = 0, string cate = "", string dep = "")
    {
        SKU = sku;
        this->name = name;
        description = desc;
        salePrice = sPrice;
        purchasePrice = pPrice;
        stockQuantity = quantity;
        category = cate;
        department = dep;
    }

    void addProduct()
    {
        cout << "------------------------------------" << endl;
        cout << "Enter the SKU: ";
        cin >> SKU;
        cin.ignore();

        cout << "Enter the name of product: ";
        getline(cin, name);

        cout << "Enter the description: ";
        getline(cin, description);

        cout << "Enter the sale price: ";
        cin >> salePrice;

        cout << "Enter the purchase price: ";
        cin >> purchasePrice;

        cout << "Enter the stock quantity: ";
        cin >> stockQuantity;
        cin.ignore();

        cout << "Enter the category: ";
        getline(cin, category);

        cout << "Enter the department: ";
        getline(cin, department);
    }

    void updateStock(Product &other)
    {
        if (other.SKU == SKU)
        {
            int quantity;
            cout << "Enter the stocks you want to add: " << endl;
            cin >> quantity;
            other.stockQuantity += quantity;
            cout << "Your stocks has been updated" << endl;
        }
        else
        {
            cout << "Product not found" << endl;
        }
    }
    void displayStock() const
    {
        cout << "========================" << endl;
        cout << "Product Name: " << name << endl;
        cout << "Product SKU number: " << SKU << endl;
        cout << "Product Description: " << description << endl;
        cout << "Sales Price: " << salePrice << endl;
        cout << "Purchase Price: " << purchasePrice << endl;
        cout << "Stock Quantity" << stockQuantity << endl;
        cout << "Department: " << department << endl;
        cout << "Category Type: " << category << endl;
    }
};

#endif