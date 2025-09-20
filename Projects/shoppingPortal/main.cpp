#include <iostream>
using namespace std;

void showMenu()
{
    cout << "-------------------------" << endl;
    cout << "Welcome to Shopping Prtal System" << endl;
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
            // showAdmin()
            break;
        }
        case 2:
        {
            // showCustomer()
            break;
        }
        case 3:
        {
            // showVendor()
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