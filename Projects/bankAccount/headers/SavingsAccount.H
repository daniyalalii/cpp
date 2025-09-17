#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "./BankAccount.H"

class SavingsAccount : public BankAccounts
{
private:
    bool status;

public:
    void withdraw(double amount)
    {
        if (getBalance() < 25)
        {
            status = true;
            cout << "Your account is on hold!" << endl;
            cout << "Your account balance should be more than $25" << endl;
            return;
        }
        else
        {
            withdrawal(amount);
        }
    }
    void depositAmount(double amount)
    {
        if (status && getBalance() < 25)
        {
            if (amount < 25)
            {
                cout << "Your account is on hold" << endl;
                cout << "Low on Balance" << endl;
                cout << "please Deposit more amount to continue using your account!" << endl;
                setBalance(amount);
                return;
            }
        }
        else
        {
            deposit(amount);
            if (status)
            {
                status = false;
            }
        }
    }
    void monthlyProc()
    {
        if (getNumWithdrawal() > 4)
        {
            int extraFees = getNumWithdrawal() - 4;
            setServiceCharges(extraFees);
            BankAccounts::monthlyProc();
            if(getBalance()<25){
                status = true;
                cout<<"Your account goes on hold!"<<endl;
                return;
            }
            return;
        }
    }
};

#endif