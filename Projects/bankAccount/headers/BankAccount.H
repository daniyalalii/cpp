#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;

class BankAccounts
{
private:
    double balance;
    double monthlyServiceCharges;
    int numDepositsPerMonth;
    int numWithdrawalsPerMonth;
    int annualInterestRate;

public:
    BankAccounts(double bal = 0.0, int interestRate = 0)
    {
        balance = bal;
        annualInterestRate = interestRate;
    }
    double getBalance() const
    {
        return balance;
    }
    void setBalance(double amount)
    {
        balance += amount;
    }
    int getNumWithdrawal() const
    {
        return numWithdrawalsPerMonth;
    }
    double getServiceCharges() const
    {
        return monthlyServiceCharges;
    }
    virtual void setServiceCharges(double val)
    {
        monthlyServiceCharges += val;
    }
    virtual void deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Error! cannot desposit that amount\nPlease try again later" << endl;
            return;
        }
        else
        {
            balance += amount;
            cout << "Your amount has been deposited to your account" << endl;
            numDepositsPerMonth++;
        }
    }
    virtual void withdrawal(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Amount!" << endl;
            return;
        }
        else
        {
            balance -= amount;
            cout << "You have successfully withdrawal: $" << amount << endl;
            numWithdrawalsPerMonth++;
        }
    }
    virtual void calculateInterest()
    {
        double monthlyInterestRate = (annualInterestRate / 12);
        double monthlyInterest = balance * monthlyInterestRate;
        balance = balance + monthlyInterest;
        cout << "Monthly Interest Rate added!" << endl;
        cout << "Balance Updated" << endl;
    }
    virtual void monthlyProc()
    {
        balance -= monthlyServiceCharges;
        cout << "Monthly charges from your account has been deducted" << endl;
        calculateInterest();
        numWithdrawalsPerMonth = 0;
        numDepositsPerMonth = 0;
        // monthlyServiceCharges = 0;
    }
    virtual void display() const
    {
        cout << "Current Balance: $" << balance << endl;
        cout << "Number of Deposits this month: " << numDepositsPerMonth << endl;
        cout << "Number of Withdrawals this month: " << numWithdrawalsPerMonth << endl;
        cout << "Monthly Service Charges: $" << monthlyServiceCharges << endl;
    }
};

#endif