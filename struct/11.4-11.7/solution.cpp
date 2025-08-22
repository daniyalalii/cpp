// use question.md for reference
#include <iostream>
using namespace std;

struct Product
{
    string description; // Product description
    int partNum;        // Part number
    double cost;        // Product cost
};

int main()
{
    const int size = 100;
    Product P[size];

    for (int i = 0; i < size; i++)
    {
        P[i].description = "";
        P[i].cost = 0.0;
        P[i].partNum = 0;
    }

    cout << "Printing details after creating empty structure\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Displaying the data set " << i + 1 << endl;
        cout << P[i].description << endl;
        cout << P[i].partNum << endl;
        cout << P[i].cost << endl;
    }

    cout << "Entering the data in the struct" << endl;
    P[0].description = "Claw Hammer";
    P[0].partNum = 547;
    P[0].cost = 8.29;

        cout << "\nPrinting details after entering first data in structure\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Displaying the data set " << i + 1 << endl;
        cout << P[i].description << endl;
        cout << P[i].partNum << endl;
        cout << P[i].cost << endl;
    }
    return 0;
}