#include "./headers/store.h"
#include "./headers/inventory.h"
#include "./headers/item.h"
#include "./headers/order.h"

using namespace std;

void menu()
{
    cout << "\n===== Grocery Management System =====" << endl;
    cout << "1. Add/Remove items in inventory" << endl;
    cout << "2. Create new order" << endl;
    cout << "3. Modify pending order" << endl;
    cout << "4. Complete an order" << endl;
    cout << "5. View inventory" << endl;
    cout << "6. View pending orders (sorted)" << endl;
    cout << "7. View completed orders" << endl;
    cout << "8. Calculate total revenue" << endl;
    cout << "9. Exit program" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    store myStore;
    inventory myInventory;

    item item1("Apple", "12345", 0.5, 100);
    item item2("Banana", "67890", 0.3, 150);

    myInventory.addItem(item1);
    myInventory.addItem(item2);

    while (true)
    {
        menu();
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "1. Add item\n2. Remove item\nEnter choice: ";
            int subChoice;
            cin >> subChoice;
            if (subChoice == 1) {
                string name, code;
                double price;
                int quantity;
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item code: ";
                cin >> code;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;
                item newItem(name, code, price, quantity);
                myInventory.addItem(newItem);
                cout << "Item added.\n";
            } else if (subChoice == 2) {
                string code;
                cout << "Enter item code to remove: ";
                cin >> code;
                myInventory.removeItem(code);
                cout << "Item removed (if existed).\n";
            }
            break;
        }
        case 2:
        {
            order newOrder;
            string code;
            string paymentMethod;
            int quantity;
            cout << "Enter item code for order: ";
            cin >> code;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout<<"Enter paymentMethod (Cash/Card): ";
            cin>>paymentMethod;
            item* orderedItem = myInventory.findItem(code);
            if (orderedItem && orderedItem->getQuantity() >= quantity) {
                newOrder.addItemInOrder(orderedItem, quantity, paymentMethod);
                myStore.addPendingOrder(newOrder);
                orderedItem->addQuantity(orderedItem->getQuantity() - quantity);
                cout << "Order created.\n";
            } else {
                cout << "Item not found or insufficient quantity.\n";
            }
            break;
        }
        case 3:
        {
            int orderId;
            cout << "Enter pending order ID to modify: ";
            cin >> orderId;
            myStore.modifyPendingOrder(orderId);
            break;
        }
        case 4:
        {
            int orderId;
            cout << "Enter order ID to complete: ";
            cin >> orderId;
            myStore.completeOrder(orderId);
            break;
        }
        case 5:
            myInventory.printAllItems();
            break;
        case 6:
            myStore.displayPendingOrdersSorted();
            break;
        case 7:
            myStore.displayCompletedOrders();
            break;
        case 8:
            myStore.calculateRevenue();
            break;
        case 9:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}