#ifndef ADMIN_H
#define ADMIN_H
#include "./User.h"
#include "./inventory.h"
#include "./Order.h"
#include <vector>

class Admin : public User
{
public:
    // Add a new product to the inventory
    void addProduct(Inventory& inventory, const Product& product){
        inventory.addProduct();
    }

    // Update an existing product in the inventory
    void updateProduct(Inventory& inventory, int productId){
        inventory.updateQuantity(productId);
    }

    // Delete a product from the inventory
    void deleteProduct(Inventory& inventory, int productId){
        inventory.deleteProduct(productId);
    }

    // Manage users (e.g., view, add, remove users)
    void manageUsers(vector<User>& users){
        cout << "Managing users..." << endl;
    }

    // View reports (e.g., sales, inventory status)
    void viewReports(const vector<Order>& orders, const Inventory& inventory){
        cout << "Viewing reports..." << endl;
        cout << "Total Orders: " << orders.size() << endl;
        inventory.displayInventory();
    }
};

#endif 