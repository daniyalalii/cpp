#include <iostream>
using namespace std;

bool searchAccount(int[], int, int);

int main()
{
    const int size = 18;
    int accounts[size] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int input;
    cout << "Enter the account number you want to find: " << endl;
    cin >> input;

    if (searchAccount(accounts, size, input))
    {
        cout << "Account is present in the list!" << endl;
    }
    else
    {
        cout << "Account is not present in the list!" << endl;
    }

    return 0;
}

bool searchAccount(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }
    return false;
}
