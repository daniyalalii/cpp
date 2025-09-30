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
    void adminResponse(){
        extern Inventory inventory;
        Product product;
        vector<User> users;
        vector<Order> orders;
        cout<<"Enter your choice: "<<endl;
        cout<<"0. Exit admin menu"<<endl;
        cout<<"1. Add products"<<endl;
        cout<<"2. Update products"<<endl;
        cout<<"3. Delete products"<<endl;
        cout<<"4. Manage users"<<endl;
        cout<<"5. View reports"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                // Add products
                addProduct(inventory, product);
                break;
            case 2:
                // Update products
                cout<<"Enter product ID to update: ";
                int productId;
                cin>>productId;
                updateProduct(inventory, productId);
                break;
            case 3:
                // Delete products
                
                cout<<"Enter product ID to delete: ";
                int pId;
                cin>>pId;
                deleteProduct(inventory, pId);
                break;
            case 4:
                // Manage users
                manageUsers(users);
                break;
            case 5:
                // View reports
                viewReports(orders, inventory);
                break;
            case 0:
                cout << "Exiting admin menu." << endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
};

#endif