#include <iostream>
using namespace std;

const int maxAccountSize = 10;
struct customerAccounts
{
    string Name;
    string Address;
    string State;
    string City;
    string PostalCode;
    string TelephoneNumber;
    double AccountBalance;
    string LastPaymentDate;
};
void inputData(customerAccounts data[]){
    for (int i = 0; i < maxAccountSize; i++) {
        cout << "Enter details for account " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> data[i].Name;
        cout << "Address: ";
        cin >> data[i].Address;
        cout << "State: ";
        cin >> data[i].State;
        cout << "City: ";
        cin >> data[i].City;
        cout << "Postal Code: ";
        cin >> data[i].PostalCode;
        cout << "Telephone Number: ";
        cin >> data[i].TelephoneNumber;
        cout << "Account Balance: ";
        cin >> data[i].AccountBalance;
        cout << "Last Payment Date: ";
        cin >> data[i].LastPaymentDate;
    }
}

void updateData(customerAccounts data[]){
    string name;
    cout << "Enter the name of the customer to update: ";
    cin >> name;
    for (int i = 0; i < maxAccountSize; i++) {
        if (data[i].Name == name) {
            cout << "Enter new details for " << name << ":" << endl;
            cout << "Address: ";
            cin >> data[i].Address;
            cout << "State: ";
            cin >> data[i].State;
            cout << "City: ";
            cin >> data[i].City;
            cout << "Postal Code: ";
            cin >> data[i].PostalCode;
            cout << "Telephone Number: ";
            cin >> data[i].TelephoneNumber;
            cout << "Account Balance: ";
            cin >> data[i].AccountBalance;
            cout << "Last Payment Date: ";
            cin >> data[i].LastPaymentDate;
            return;
        }
    }
    cout << "Customer not found!" << endl;
}

void displayData(const customerAccounts data[]){
    for (int i = 0; i < maxAccountSize; i++) {
        if (!data[i].Name.empty()) {
            cout << "-----------------------------------" << endl;
            cout << "Account " << i + 1 << ":" << endl;
            cout << "Name: " << data[i].Name << endl;
            cout << "Address: " << data[i].Address << endl;
            cout << "State: " << data[i].State << endl;
            cout << "City: " << data[i].City << endl;
            cout << "Postal Code: " << data[i].PostalCode << endl;
            cout << "Telephone Number: " << data[i].TelephoneNumber << endl;
            cout << "Account Balance: " << data[i].AccountBalance << endl;
            cout << "Last Payment Date: " << data[i].LastPaymentDate << endl;
        }
    }
}

int main()
{
    customerAccounts accounts[maxAccountSize];
    int choice;
    do
    {
        cout << "------Welcome to Account Service------" << endl;
        cout << "1- Enter Data" << endl;
        cout << "2- change Data" << endl;
        cout << "3- Display Data" << endl;
        cout << "0- Exit Program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            inputData(accounts);
            break;
        case 2:
            updateData(accounts);
            break;
        case 3:
            displayData(accounts);
            break;
        case 0:
            cout << "Ending the program!" << endl;
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}