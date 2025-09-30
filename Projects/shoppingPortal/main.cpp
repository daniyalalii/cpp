#include <iostream>
#include "Admin.h"
#include "Customer.h"
#include "Vendor.h"
using namespace std;

void showMenu()
{
    cout << "-------------------------" << endl;
    cout << "Welcome to Shopping Portal System" << endl;
    cout << "Enter your Login Type" << endl;
    cout << "1- Admin" << endl;
    cout << "2- Customer" << endl;
    cout << "3- Vendor" << endl;
    cout << "0- Exit The System" << endl;
}
int main()
{
    int input;
    do
    {
        showMenu();
        cin >> input;
        switch (input)
        {
        case 1:
        {
            Admin admin;
            admin.adminResponse();
            break;
        }
        case 2:
        {
            Customer customer;
            customer.customerResponse();
            break;
        }
        case 3:
        {
            Vendor vendor;
            vendor.vendorResponse();
            break;
        }
        case 0:
        {
            cout << "Thank you for using the Program" << endl;
            break;
        }

        default:
        {
            cout << "Enter correct input" << endl;
            break;
        }
        }
    } while (input != 0);
    return 0;
}