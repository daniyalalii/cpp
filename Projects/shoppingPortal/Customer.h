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
    double billAmount;
public:
    Customer(int id = 0, int number = 0, string n = "", string em = "", string pass = "", string addr = "", bool premium = false)
        : User(id, number, n, em, pass, addr), isPremium(premium), billAmount(0.0) {}
    void addToCart(Product& product){
        cart.addItem(product, 1); // Default quantity is 1
    }
    void removeFromCart(Product& product){
        cart.removeItem(product.getSKU());
    }
    void checkout(){
        extern Inventory inventory;
        double totalCost = 0.0;
        for (const auto &item : cart.cartItems) {
            totalCost += item.product.getSalePrice() * item.quantity;
            // Update stock in inventory
            Product* invProduct = inventory.getProductBySKU(item.product.getSKU());
            if (invProduct) {
                int newStock = invProduct->getStockQuantity() - item.quantity;
                if (newStock < 0) newStock = 0; // Prevent negative stock
                invProduct->setStockQuantity(newStock);
            }
        }
        totalCost -= totalCost * getDiscount(); // Apply discount
        billAmount += totalCost;
        cout << "Total cost at checkout: $" << totalCost << endl;
        cart.clearCart();
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
    void checkOutCart() const{
        cart.getNumItemsinCart();
        cart.getCostofCart();
    }
    void customerResponse(){
        extern Inventory inventory;
        int choice;
        do {
            cout << "\n=========== INVENTORY ===========\n";
            inventory.displayInventory();
            cout << "\nEnter your choice: " << endl;
            cout << "0. Exit customer menu" << endl;
            cout << "1. Add to cart" << endl;
            cout << "2. Remove from cart" << endl;
            cout << "3. Checkout" << endl;
            cout << "4. View order history" << endl;
            cin >> choice;
            switch(choice){
                case 1:
                    // Add to cart
                    {
                        int sku;
                        cout << "Enter SKU of product to add: ";
                        cin >> sku;
                        Product* product = inventory.getProductBySKU(sku);
                        if (product) {
                            addToCart(*product);
                        } else {
                            cout << "Product not found in inventory." << endl;
                        }
                    }
                    break;
                case 2:
                    // Remove from cart
                    {
                        int sku;
                        cout << "Enter SKU of product to remove: ";
                        cin >> sku;
                        Product* product = inventory.getProductBySKU(sku);
                        if (product) {
                            removeFromCart(*product);
                        } else {
                            cout << "Product not found in inventory." << endl;
                        }
                    }
                    break;
                case 3:
                    // Checkout
                    checkout();
                    cout << "Thank you for shopping! Returning to main menu..." << endl;
                    return;
                case 4:
                    // View order history
                    viewOrderHistory();
                    break;
                case 0:
                    cout << "Exiting customer menu." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        } while (choice != 0);
    }
};

#endif