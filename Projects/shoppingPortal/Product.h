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
    void setSKU(int id)
    {
        SKU = id;
    }

    int getSKU() const
    {
        return SKU;
    }
    void setName(string n)
    {
        name = n;
    }
    void setDescription(string disc)
    {
        description = disc;
    }
    void setSalePrice(double price)
    {
        salePrice = price;
    }
    double getSalePrice() const
    {
        return salePrice;
    }
    void setPurchasePrice(double price)
    {
        purchasePrice = price;
    }
    void setStockQuantity(int quantity)
    {
        stockQuantity = quantity;
    }
    void setCategory(string cat)
    {
        category = cat;
    }
    void setDepartment(string dep)
    {
        department = dep;
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