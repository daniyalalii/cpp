#include <iostream>
#include <iomanip>
using namespace std;

class retailItem
{
private:
    string description;
    int unitsOnHand;
    double price;

public:
    retailItem(string desc, int units, double p)
    {
        description = desc;
        unitsOnHand = units;
        price = p;
    }
    void setdescription(string disc)
    {
        description = disc;
    }
    void setUnits(int units)
    {
        unitsOnHand = units;
    }
    void setPrice(double p)
    {
        price = p;
    }
    void getData()
    {
        cout << "---------------------------" << endl;
        cout << "Description: " << description << endl;
        cout << "Units on Hand: " << unitsOnHand << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "Price: " << price << endl;
        cout << "---------------------------" << endl;
    }
};
int main()
{
    retailItem item1("Jacket", 12, 59.95);
    retailItem item2("Designer Jeans", 40, 34.65);
    retailItem item3("Shirt", 20, 29.45);

    cout << "Item 1" << endl;
    item1.getData();
    cout << "Item 2" << endl;
    item2.getData();
    cout << "Item 3" << endl;
    item3.getData();

    return 0;
}