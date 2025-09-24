#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "./User.h"
#include "./Cart.h"
#include "./Product.h"

class Customer : public User
{
private:
    Cart cart;
    bool isPremium;
public:
    Customer(int id = 0, int number = 0, string n = "", string em = "", string pass = "", string addr = "", bool premium = false)
        : User(id, number, n, em, pass, addr), isPremium(premium) {}
    void addToCart(Product* product){
        cart.addItem(*product, 1); // Default quantity is 1
    }
    void removeFromCart(Product* product){
        cart.removeItem(product->getSKU());
    }
    void checkout(){
        double totalCost = 0.0;
        for (const auto &item : cart.cartItems) {
            totalCost += item.product.getSalePrice() * item.quantity;
        }
        cout << "Total cost at checkout: $" << totalCost << endl;
    }
    void viewOrderHistory() const{
        cout << "Viewing order history..." << endl;
    }
    double getDiscount() const{
        return isPremium ? 0.1 : 0.0; // 10% discount for premium customers
    }
    void displayCustomerInfo(){
        User::displayInfo(); // From User class
        cout << "Premium Customer: " << (isPremium ? "Yes" : "No") << endl;
    }
};

#endif