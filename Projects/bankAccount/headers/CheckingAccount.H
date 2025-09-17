#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "./BankAccount.H"

class CheckingAccount : public BankAccounts
{
public:
    void withdraw(double amount)
    {
        if (amount > getBalance())
        {
            setServiceCharges(15);
            // BankAccounts::monthlyProc();
            cout << "Insufficient Amount! You cannot withdraw amount" << endl;
            cout << "Fee of $15 added" << endl;
            return;
        }
        else
        {
            withdrawal(amount);
        }
    }
    void monthlyProc()
    {
        int extraCharges = 5 + (getNumWithdrawal() * 0.10);
        setServiceCharges(extraCharges);
        cout << "Extra Fee deducted!" << endl;
    }
};

#endif