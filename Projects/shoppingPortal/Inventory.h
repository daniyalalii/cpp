#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "./Product.h"

class Inventory : public Product
{
private:
    vector<Product> products;

public:
    void addProduct()
    {
        int sku, quantity;
        string name, description, category, department;
        double salePrice, purchasePrice;

        cout << "------------------------------------" << endl;
        cout << "Enter the SKU: ";
        cin >> sku;
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
        cin >> quantity;
        cin.ignore();

        cout << "Enter the category: ";
        getline(cin, category);

        cout << "Enter the department: ";
        getline(cin, department);

        Product p(sku, name, description, salePrice, purchasePrice, quantity, category, department);

        // product is added to inventory
        products.push_back(p);

        cout << "✅ Product added successfully!" << endl;
    }

    void displayInventory() const
    {
        cout << "\n=========== INVENTORY ===========\n";
        if (products.empty())
        {
            cout << "Inventory is empty!" << endl;
            return;
        }

        for (const auto &p : products)
        {
            p.displayStock();
        }
    }

    void deleteProduct(int sku)
    {
        auto it = remove_if(products.begin(), products.end(), [sku](const Product &p)
                            { return p.getSKU() == sku; });

        if (it != products.end())
        {
            products.erase(it, products.end());
            cout << "✅ Product with SKU " << sku << " deleted successfully!" << endl;
        }
        else
        {
            cout << "❌ Product with SKU " << sku << " not found!" << endl;
        }
    }

    void updateQuantity(int sku)
    {
        for (auto &p : products)
        {
            if (p.getSKU() == sku)
            {
                p.updateStock(p);
                return;
            }
        }
        cout << "❌ Product with SKU " << sku << " not found!" << endl;
    }

    void searchProduct(int sku) const
    {
        for (const auto &p : products)
        {
            if (p.getSKU() == sku)
            {
                p.displayStock();
                return;
            }
        }
        cout << "❌ Product with SKU " << sku << " not found!" << endl;
    }
};

#endif
