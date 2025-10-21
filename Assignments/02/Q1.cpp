#include <iostream>
using namespace std;

class Item
{
private:
    string name;
    string code;
    float price;
    int quantity;
    bool isAvailible;  //to check the aviailiblity of the item

public:
    // constructor
    Item(string name = "", string code = "", float price = 0.0, int quantity = 0, bool isAvailible = true) : name(name), code(code), price(price), quantity(quantity), isAvailible(isAvailible) {}
    // setters
    void setName(string name)
    {
        this->name = name;
    }
    void setCode(string code)
    {
        this->code = code;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    void setAvailibility(bool isAvailible)
    {
        this->isAvailible = isAvailible;
    }
    // getters
    string getName() const
    {
        return name;
    }
    string getCode() const
    {
        return code;
    }
    float getPrice() const
    {
        return price;
    }
    int getQuantity() const
    {
        return quantity;
    }
    bool getAvailibility() const
    {
        return isAvailible;
    }
    // display function
    void displayItem() const
    {
        cout << "=========================================" << endl;
        cout << "Item Name: " << name << endl;
        cout << "Item Code: " << code << endl;
        cout << "Item Price: $" << price << endl;
        cout << "Item Quantity: " << quantity << endl;
        cout << "Item Availability: " << (isAvailible ? "Available" : "Not Available") << endl;
        cout << "=========================================" << endl;
    }
    // function to update quantity and availability
    void updateQuantity(int amount)
    {
        quantity += amount;
        if (quantity <= 0)
        {
            quantity = 0;
            isAvailible = false;
        }
        else
        {
            isAvailible = true;
        }
    }
    // update price by percentage
    void updatePrice(float percentChange)
    {
        float newPrice = price + (price * percentChange / 100);
        if (newPrice >= 0)
        {
            price = newPrice;
        }
    }
    // to check if item is out of stock
    bool isOutOfStock() const
    {
        return quantity == 0;
    }
    // marking item as out of stock
    void markOutOfStock()
    {
        quantity = 0;
        isAvailible = false;
    }
    // == operator overload to compare items by code
    bool operator==(const Item &other) const
    {
        return this->code == other.code;
    }
    // destructor
    ~Item() {}
};
// vecnding machine class
class VendingMachine
{
private:
    Item *items; // items class used 
    int capacity;  // maximum capacity of the vending machine
    int itemCount; // current number of items in the vending machine
    int machineID;
    // static variables
    static int totalMachines;
    static int totalSalesCount;
    static float totalRevenue;

public:
    // default constructor
    VendingMachine() : capacity(0), itemCount(0)
    {
        items = nullptr;
        totalMachines++;
        machineID = totalMachines;
    }

    // parameterized constructor
    VendingMachine(int capacity) : capacity(capacity), itemCount(0)
    {
        items = new Item[capacity];
        totalMachines++;
        machineID = totalMachines;
    }
    // copy constructor
    VendingMachine(const VendingMachine &other) : capacity(other.capacity), itemCount(other.itemCount), machineID(other.machineID)
    {
        items = new Item[capacity];
        for (int i = 0; i < itemCount; i++)
        {
            items[i] = other.items[i];
        }
    }

    // overloadin += operator
    VendingMachine &operator+=(const Item &newItem)
    {
        if (itemCount < capacity)
        {
            items[itemCount] = newItem;
            itemCount++;
        }
        else
        {
            cout << "Vending Machine is at full capacity!" << endl;
        }
        return *this;
    }
    // overloading -= operator
    VendingMachine &operator-=(const string &itemCode)
    {
        for (int i = 0; i < itemCount; i++)
        {
            if (items[i].getCode() == itemCode)
            {
                for (int j = i; j < itemCount - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                itemCount--;
                break;
            }
        }
        return *this;
    }
    // overloading ++ (prefix) to Increase all item prices by 5%
    VendingMachine &operator++()
    {
        for (int i = 0; i < itemCount; i++)
        {
            items[i].updatePrice(5.0);
        }
        return *this;
    }
    // overloading -- (postfix) to Decrease all item prices by 5%
    VendingMachine operator--(int)
    {
        VendingMachine temp = *this;
        for (int i = 0; i < itemCount; i++)
        {
            items[i].updatePrice(-5.0);
        }
        return temp;
    }
    // overloading [] operator to get 2nd index item
    Item &operator[](int index)
    {
        if (index >= 0 && index < itemCount)
        {
            return items[1];
        }
        else
        {
            cout << "Index out of bounds, returning first item." << endl;
            return items[0];
        }
    }
    // overloading + operator to merge two vending machines
    VendingMachine operator+(const VendingMachine &other) const
    {
        // new machine 
        VendingMachine merged;

        // new machine's capacity will be sum of other two's
        merged.capacity = this->capacity + other.capacity;
        merged.items = new Item[merged.capacity];
        merged.itemCount = 0;

        // copy the items from first machine
        for (int i = 0; i < this->itemCount; i++)
        {
            merged.items[merged.itemCount++] = this->items[i];
        }

        // merge items from second machine
        for (int j = 0; j < other.itemCount; j++)
        {
            bool found = false;

            for (int k = 0; k < merged.itemCount; k++)
            {
                if (merged.items[k].getCode() == other.items[j].getCode())
                {
                    // if items are same then combine quantity and average the price
                    int totalQty = merged.items[k].getQuantity() + other.items[j].getQuantity();
                    float avgPrice = (merged.items[k].getPrice() + other.items[j].getPrice()) / 2.0;
                    merged.items[k].setQuantity(totalQty);
                    merged.items[k].setPrice(avgPrice);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                // if items are unique then just add to merged machine
                merged.items[merged.itemCount++] = other.items[j];
            }
        }

        return merged;
    }

    // deep copy assignment operator
    VendingMachine &operator=(const VendingMachine &other)
    {
        if (this != &other)
        {
            delete[] items;
            capacity = other.capacity;
            itemCount = other.itemCount;
            machineID = other.machineID;
            items = new Item[capacity];
            for (int i = 0; i < itemCount; i++)
            {
                items[i] = other.items[i];
            }
        }
        return *this;
    }
    // functions
    void addItems(const Item &newItem)
    {
        *this += newItem;
    }
    void removeItems(const string &itemCode)
    {
        *this -= itemCode;
    }
    void displayItems() const
    {
        cout<<"=================================="<<endl;
        cout << "Vending Machine ID: " << machineID << endl;
        cout << "Total Items: " << itemCount << "/" << capacity << endl;
        for (int i = 0; i < itemCount; i++)
        {
            items[i].displayItem();
        }
        cout<<"=================================="<<endl;
    }
    // function  to restock an item
    void restockItem(const string &itemCode, int amount)
    {
        for (int i = 0; i < itemCount; i++)
        {
            if (items[i].getCode() == itemCode)
            {
                items[i].updateQuantity(amount);
                break;
            }
        }
    }
    // function to adjust the prices
    void adjustPrices(float percentChange)
    {
        if (percentChange > 0)
        {
            ++(*this);
        }
        else
        {
            (*this)--;
        }
    }

    void displayMachineInfo() const
    {
        cout<<"=================================="<<endl;
        cout << "Vending Machine ID: " << machineID << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Current Item Count: " << itemCount << endl;
        cout<<"=================================="<<endl;
    }

    // function to purchase an item
    void purchaseItem(const string &itemCode)
    {
        for (int i = 0; i < itemCount; i++)
        {
            if (items[i].getCode() == itemCode)
            {
                if (items[i].getAvailibility() && items[i].getQuantity() > 0)
                {
                    items[i].updateQuantity(-1);
                    totalSalesCount++;
                    totalRevenue += items[i].getPrice();
                    cout << "Purchased: " << items[i].getName() << " for $" << items[i].getPrice() << endl;
                }
                else
                {
                    cout << "Item is out of stock!" << endl;
                }
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    int getMachineID() const
    {
        return machineID;
    }
    float getTotalRevenue() const
    {
        return totalRevenue;
    }
    static void displayGlobalStats()
    {
        cout<<"=================================="<<endl;
        cout << "Total Vending Machines: " << totalMachines << endl;
        cout << "Total Sales Count: " << totalSalesCount << endl;
        cout << "Total Revenue: $" << totalRevenue << endl;
        cout<<"=================================="<<endl;
    }
    // friend class for generating Report
    friend class ReportGenerator;
    // destructor
    ~VendingMachine()
    {
        delete[] items;
    }
};
int VendingMachine::totalMachines = 0;
int VendingMachine::totalSalesCount = 0;
float VendingMachine::totalRevenue = 0.0;

// friend class for generating Report
class ReportGenerator
{
public:
    void generateSystemReport(VendingMachine *machines[], int count)
    {
        cout << "======== System Report ========" << endl;
        cout << "Total Machines: " << VendingMachine::totalMachines << endl;
        cout << "Total Items Sold: " << VendingMachine::totalSalesCount << endl;
        cout << "Total Revenue: " << VendingMachine::totalRevenue << endl;

        for (int i = 0; i < count; ++i)
        {
            machines[i]->displayMachineInfo();
            cout << "Machine ID: " << machines[i]->getMachineID() << endl;
            cout << "Earnings: " << machines[i]->getTotalRevenue() << endl;
            cout<<"=================================="<<endl;
        }
    }
};
// menu function
void menu()
{
    cout << "====== SMART VENDING MACHINE SYSTEM ======" << endl;
    cout << "1. Create New Vending Machine" << endl;
    cout << "2. Add Item to Machine" << endl;
    cout << "3. Remove Item from Machine" << endl;
    cout << "4. Restock an Item" << endl;
    cout << "5. Increase All Prices by 5% (++ Operator)" << endl;
    cout << "6. Decrease All Prices by 5% (-- Operator)" << endl;
    cout << "7. Purchase an Item" << endl;
    cout << "8. Merge Two Vending Machines (+ Operator)" << endl;
    cout << "9. Display Items of a Machine" << endl;
    cout << "10. Show Global Statistics" << endl;
    cout << "11. Generate System Report" << endl;
    cout << "0. Exit" << endl;
}
int main()
{
    VendingMachine *machines[10];
    int machineCount = 0;
    int choice;
    ReportGenerator reportGen;
    do
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        // add new vending machine
        case 1:
        {
            int capacity;
            cout << "Enter capacity of new Vending Machine: ";
            cin >> capacity;
            machines[machineCount++] = new VendingMachine(capacity);
            cout << "Vending Machine created with ID: " << machines[machineCount - 1]->getMachineID() << endl;
            break;
        }
        // to add item in vending machine
        case 2:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to add item: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                string name, code;
                float price;
                int quantity;
                cout << "Enter Item Name: ";
                cin >> name;
                cout << "Enter Item Code: ";
                cin >> code;
                cout << "Enter Item Price: ";
                cin >> price;
                cout << "Enter Item Quantity: ";
                cin >> quantity;
                Item newItem(name, code, price, quantity, quantity > 0);
                selectedMachine->addItems(newItem);
                cout << "Item added successfully!" << endl;
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to remove an item from vending machine
        case 3:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to remove item: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                string code;
                cout << "Enter Item Code to remove: ";
                cin >> code;
                selectedMachine->removeItems(code);
                cout << "Item removed successfully!" << endl;
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to restock the items of vending machine
        case 4:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to restock item: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                string code;
                int amount;
                cout << "Enter Item Code to restock: ";
                cin >> code;
                cout << "Enter amount to restock: ";
                cin >> amount;
                selectedMachine->restockItem(code, amount);
                cout << "Item restocked successfully!" << endl;
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to increase all item prices by 5%
        case 5:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to increase prices: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                ++(*selectedMachine);
                cout << "All item prices increased by 5%!" << endl;
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to decrease all item prices by 5%
        case 6:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to decrease prices: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                (*selectedMachine)--;
                cout << "All item prices decreased by 5%!" << endl;
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to purchase an item from vending machine
        case 7:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to purchase item from: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                string code;
                cout << "Enter Item Code to purchase: ";
                cin >> code;
                selectedMachine->purchaseItem(code);
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to merge two vending machines
        case 8:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID1, machineID2;
            cout << "Enter the IDs of the two Vending Machines to merge: ";
            cin >> machineID1 >> machineID2;
            VendingMachine *machine1 = nullptr;
            VendingMachine *machine2 = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID1)
                {
                    machine1 = machines[i];
                }
                if (machines[i]->getMachineID() == machineID2)
                {
                    machine2 = machines[i];
                }
            }
            if (machine1 && machine2)
            {
                if (machineCount >= 10)
                {
                    cout << "Cannot add merged machine: storage is full." << endl;
                }
                else
                {
                    // creating a new merged machine using the overloaded + operator
                    VendingMachine *mergedMachine = new VendingMachine(*machine1 + *machine2);
                    machines[machineCount++] = mergedMachine;
                    cout << "Machines " << machineID1 << " and " << machineID2
                         << " merged successfully! New Machine ID: "
                         << mergedMachine->getMachineID() << endl;
                }
            }
            else
            {
                cout << "One or both Vending Machines not found!" << endl;
            }
            break;
        }
        // to display items of a vending machine
        case 9:
        {
            if (machineCount == 0)
            {
                cout << "No Vending Machines available. Please create one first." << endl;
                break;
            }
            int machineID;
            cout << "Enter Vending Machine ID to view items: ";
            cin >> machineID;
            VendingMachine *selectedMachine = nullptr;
            for (int i = 0; i < machineCount; i++)
            {
                if (machines[i]->getMachineID() == machineID)
                {
                    selectedMachine = machines[i];
                    break;
                }
            }
            if (selectedMachine)
            {
                selectedMachine->displayItems();
            }
            else
            {
                cout << "Vending Machine not found!" << endl;
            }
            break;
        }
        // to display global statistics
        case 10:
        {
            VendingMachine::displayGlobalStats();
            break;
        }
        // to generate system report
        case 11:
        {
            reportGen.generateSystemReport(machines, machineCount);
            break;
        }
        // exiting the system
        case 0:
        {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        }
    } while (choice != 0);
    for (int i = 0; i < machineCount; i++)
    {
        delete machines[i];
    }
    return 0;
}