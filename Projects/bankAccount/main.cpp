#include "BankAccount.H"
#include "SavingsAccount.H"
#include "CheckingAccount.H"

void showMenu()
{
    cout << "----------------------------------------" << endl;
    cout << "Welcome to Bank Account System" << endl;
    cout << "1- create an Account" << endl;
    cout << "2- view Your Account Details" << endl;
    cout << "3- Withdraw Money to your account" << endl;
    cout << "4- Deposit Money to your account" << endl;
    cout << "0- End the Program!" << endl;
}

int main()
{
    int choice;
    SavingsAccount *savingsAccount = nullptr;
    CheckingAccount *checkingAccount = nullptr;

    do
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int input;
            cout << "What type of account do you want to create\n1 for SAVINGS Account\n2 for CHECKING Account" << endl;
            cin >> input;
            if (input == 1)
            {
                if (savingsAccount == nullptr)
                {
                    savingsAccount = new SavingsAccount();
                    cout << "Savings account created." << endl;
                }
                else
                {
                    cout << "Savings account already exists." << endl;
                }
            }
            else if (input == 2)
            {
                if (checkingAccount == nullptr)
                {
                    checkingAccount = new CheckingAccount();
                    cout << "Checking account created." << endl;
                }
                else
                {
                    cout << "Checking account already exists." << endl;
                }
            }
            else
            {
                cout << "Error: Invalid account type." << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Which account details do you want to view?\n1 for SAVINGS\n2 for CHECKING" << endl;
            int input;
            cin >> input;
            if (input == 1 && savingsAccount != nullptr)
            {
                savingsAccount->display();
            }
            else if (input == 2 && checkingAccount != nullptr)
            {
                checkingAccount->display();
            }
            else
            {
                cout << "Account does not exist." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Withdraw from which account?\n1 for SAVINGS\n2 for CHECKING" << endl;
            int input;
            cin >> input;
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (input == 1 && savingsAccount != nullptr)
            {
                savingsAccount->withdraw(amount);
            }
            else if (input == 2 && checkingAccount != nullptr)
            {
                checkingAccount->withdraw(amount);
            }
            else
            {
                cout << "Account does not exist." << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Deposit to which account?\n1 for SAVINGS\n2 for CHECKING" << endl;
            int input;
            cin >> input;
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            if (input == 1 && savingsAccount != nullptr)
            {
                savingsAccount->deposit(amount);
            }
            else if (input == 2 && checkingAccount != nullptr)
            {
                checkingAccount->deposit(amount);
            }
            else
            {
                cout << "Account does not exist." << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    delete savingsAccount;
    delete checkingAccount;
}