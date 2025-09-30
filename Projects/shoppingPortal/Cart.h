#ifndef CART_H
#define CART_H
#include "./Product.h"
#include <vector>
#include <algorithm>
class CartItems
{
public:
    Product product;
    int quantity;

    CartItems(Product p, int q) : product(p), quantity(q) {}
};

class Cart
{
    public:
    vector<CartItems> cartItems; // Store cart items
    void addItem(const Product &product, int quantity)
    {
        cartItems.emplace_back(product, quantity);
        cout << "✅ Product with SKU " << product.getSKU() << " added to cart!" << endl;
    }
    
    void removeItem(int sku)
    {
        auto it = remove_if(cartItems.begin(), cartItems.end(),
                            [sku](const CartItems &item)
                            { return item.product.getSKU() == sku; });
        if (it != cartItems.end())
        {
            cartItems.erase(it, cartItems.end());
            cout << "✅ Product with SKU " << sku << " removed from cart!" << endl;
        }
        else
        {
            cout << "❌ Product with SKU " << sku << " not found in cart!" << endl;
        }
    }
    void modifyItem(int sku, int newQuantity)
    {
        for (auto &item : cartItems)
        {
            if (item.product.getSKU() == sku)
            {
                item.quantity = newQuantity;
                cout << "✅ Product with SKU " << sku << " updated to quantity " << newQuantity << "!" << endl;
                return;
            }
        }
        cout << "❌ Product with SKU " << sku << " not found in cart!" << endl;
    }
    void getNumItemsinCart() const
    {
        cout << "Total unique items in cart: " << cartItems.size() << endl;
    }
    void getCostofCart() const
    {
        double totalCost = 0.0;
        for (const auto &item : cartItems)
        {
            totalCost += item.product.getSalePrice() * item.quantity;
        }
        cout << "Total cost of cart: $" << totalCost << endl;
    }
    void printTotal() const
    {
        getNumItemsinCart();
        getCostofCart();
    }
    void printItemsDescription() const
    {
        cout << "\n=========== CART ITEMS ===========\n";
        if (cartItems.empty())
        {
            cout << "Cart is empty!" << endl;
            return;
        }

        for (const auto &item : cartItems)
        {
            item.product.displayStock();
            cout << "Quantity: " << item.quantity << endl;
            cout << "-------------------------" << endl;
        }
    }
    void clearCart()
    {
        cartItems.clear();
        cout << "✅ Cart has been cleared!" << endl;
    }

};

#endif