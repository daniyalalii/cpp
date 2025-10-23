#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

class Exchange
{
private:
    static float btcToUsdRate; // change rate
    static float totalBTC;     // total btc in exchange
    static int activeWallets;  // total active wallets

    friend void updateExchangeRate(float newRate); // for admin to change the rates

public:
    static void showExchangeInfo()
    {
        cout << "BTC to USD Rate: " << btcToUsdRate << endl;
        cout << "Total BTC in Exchange: " << totalBTC << endl;
        cout << "Active Wallets: " << activeWallets << endl;
    }
    static void updateTotalBTC(float change)
    {
        totalBTC += change;
    }
    static void incrementWallets()
    {
        activeWallets++;
    }
    static void decrementWallets()
    {
        activeWallets--;
    }
    static float getBtcToUsdRate()
    {
        return btcToUsdRate;
    }
};

class Wallet
{
private:
    char *ownerName;          // dynamically allocated owner name
    string walletID;          // unique wallet ID
    string privateKey;        // random alphanumeric string
    float balance;            // BTC balance
    float *transactions;      // dynamic array for transaction history
    int transactionCount;     // number of transactions
    static int walletCounter; // static counter for assigning unique IDs

    string generateRandomKey()
    {
        string key;
        static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 6; ++i)
        {
            key += alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        return key;
    }

public:
    // default
    Wallet()
    {
        ownerName = new char[8];
        strcpy(ownerName, "Default");
        walletID = "WALLET" + to_string(++walletCounter);
        privateKey = generateRandomKey();
        balance = 0.0;
        transactions = nullptr;
        transactionCount = 0;
        Exchange::incrementWallets();
    }
    // parameterized
    Wallet(const char *name)
    {
        ownerName = new char[strlen(name) + 1];
        strcpy(ownerName, name);
        walletID = "WALLET" + to_string(++walletCounter);
        privateKey = generateRandomKey();
        balance = 0.0;
        transactions = nullptr;
        transactionCount = 0;
        Exchange::incrementWallets();
    }

    // copy constructor
    Wallet(const Wallet &other)
    {
        ownerName = new char[strlen(other.ownerName) + 1];
        strcpy(ownerName, other.ownerName);
        walletID = "WALLET" + to_string(++walletCounter);
        privateKey = generateRandomKey();
        balance = other.balance;
        transactionCount = 0;
        transactions = nullptr;
        Exchange::incrementWallets();
    }

    // Overloaded operators
    Wallet &operator+=(float deposit)
    {
        if (deposit > 0)
        {
            balance += deposit;
            float *newTransactions = new float[transactionCount + 1];
            for (int i = 0; i < transactionCount; ++i)
            {
                newTransactions[i] = transactions[i];
            }
            newTransactions[transactionCount] = deposit;
            delete[] transactions;
            transactions = newTransactions;
            transactionCount++;
            Exchange::updateTotalBTC(deposit);
        }
        return *this;
    }

    Wallet &operator-=(float withdrawal)
    {
        if (withdrawal > 0 && balance >= withdrawal)
        {
            balance -= withdrawal;
            float *newTransactions = new float[transactionCount + 1];
            for (int i = 0; i < transactionCount; ++i)
            {
                newTransactions[i] = transactions[i];
            }
            newTransactions[transactionCount] = -withdrawal;
            delete[] transactions;
            transactions = newTransactions;
            transactionCount++;
            Exchange::updateTotalBTC(-withdrawal);
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
        return *this;
    }

    Wallet &operator++()
    { // Prefix
        balance *= 1.02;
        return *this;
    }

    Wallet operator++(int)
    { // Postfix
        Wallet temp = *this;
        balance *= 1.02;
        return temp;
    }

    Wallet &operator--()
    { // Prefix
        balance *= 0.98;
        return *this;
    }

    Wallet operator--(int)
    { // Postfix
        Wallet temp = *this;
        balance *= 0.98;
        return temp;
    }

    bool operator>(const Wallet &other) const
    {
        return balance > other.balance;
    }

    bool operator<(const Wallet &other) const
    {
        return balance < other.balance;
    }

    Wallet &operator>>(Wallet &recipient)
    {
        float transferAmount;
        cout << "Enter amount to transfer: ";
        cin >> transferAmount;
        if (transferAmount > 0 && balance >= transferAmount)
        {
            *this -= transferAmount;
            recipient += transferAmount;
            cout << "Successfully transfer " << transferAmount << " btc to other wallet" << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
        return *this;
    }

    float operator[](int index) const
    {
        if (index >= 0 && index < transactionCount)
        {
            return transactions[index];
        }
        else
        {
            cout << "Invalid transaction index!" << endl;
            return 0.0;
        }
    }

    // Updating the assignment operator to generate new wallet ID and private key
    Wallet &operator=(const Wallet &other)
    {
        if (this != &other)
        {
            delete[] ownerName;
            ownerName = new char[strlen(other.ownerName) + 1];
            strcpy(ownerName, other.ownerName);
            walletID = "WALLET" + to_string(++walletCounter);
            privateKey = generateRandomKey();
            balance = other.balance;
            transactionCount = other.transactionCount;

            delete[] transactions;
            if (transactionCount > 0)
            {
                transactions = new float[transactionCount];
                for (int i = 0; i < transactionCount; ++i)
                {
                    transactions[i] = other.transactions[i];
                }
            }
            else
            {
                transactions = nullptr;
            }
        }
        return *this;
    }
    // wallet info
    void showWalletInfo() const
    {
        cout << "Owner Name: " << ownerName << endl;
        cout << "Wallet ID: " << walletID << endl;
        cout << "Private Key: " << privateKey << endl;
        cout << "Balance (BTC): " << balance << endl;
        cout << "Equivalent in USD: " << balance * Exchange::getBtcToUsdRate() << endl;
    }
    // transaction history
    void showTransactionHistory() const
    {
        cout << "Transaction History: " << endl;
        for (int i = 0; i < transactionCount; ++i)
        {
            cout << "  Transaction " << (i + 1) << ": " << transactions[i] << " BTC" << endl;
        }
    }
    // to add new transaction
    void addTransaction(float amount)
    {
        float *newTransactions = new float[transactionCount + 1];
        for (int i = 0; i < transactionCount; ++i)
        {
            newTransactions[i] = transactions[i];
        }
        newTransactions[transactionCount] = amount;
        delete[] transactions;
        transactions = newTransactions;
        transactionCount++;
    }
    // for mining the coin
    int mineCoins(int *blocks, int totalBlocks, int target, int index = 0)
    {
        if (index >= totalBlocks)
        {
            return -1;
        }
        cout << "Checking block #" << index << "..." << endl;
        if (blocks[index] == target)
        {
            cout << "Block found at index " << index << endl;
            float reward = (rand() % 5 + 1) / 100.0; // Random reward between 0.01 and 0.05 BTC
            *this += reward;
            return index;
        }
        return mineCoins(blocks, totalBlocks, target, index + 1);
    }
    // mine coin, random index to find using rand()
    void performMining()
    {
        int size = 10;
        int *blocks = new int[size];
        for (int i = 0; i < size; ++i)
        {
            blocks[i] = rand() % 10; // Random integers between 0 and 9
        }
        int target;
        cout << "Enter target number to mine: ";
        cin >> target;
        int result = mineCoins(blocks, size, target);
        if (result == -1)
        {
            cout << "Target not found in any block." << endl;
        }
        delete[] blocks;
    }

    // Updating the destructor to include a secure destruction message
    ~Wallet()
    {
        delete[] ownerName;
        delete[] transactions;
        privateKey = "";
        cout << "Wallet with ID: " << walletID << " destroyed securely." << endl;
        cout << "Private key desotroyed securely" << endl;
        Exchange::decrementWallets();
    }
};
float Exchange::btcToUsdRate = 30000.0; // initial rate
float Exchange::totalBTC = 0.0;         // initial total btc
int Exchange::activeWallets = 0;        // initial total active wallets
int Wallet::walletCounter = 0;          // initial total wallet counter

// to update new exchange rate
void updateExchangeRate(float newRate)
{
    if (newRate > 0)
    {
        Exchange::btcToUsdRate = newRate;
        cout << "Exchange rate updated successfully!\n";
    }
    else
    {
        cout << "Invalid rate entered.\n";
    }
}

// main menu
void showMenu()
{
    int choice;
    // total of 10 wallets
    Wallet *wallets[10] = {nullptr};
    int walletCount = 0;

    do
    {
        cout << "===== BlockVerse Wallet Menu =====" << endl;
        cout << "1. Create new wallet" << endl;
        cout << "2. Deposit BTC" << endl;
        cout << "3. Withdraw BTC" << endl;
        cout << "4. Transfer BTC" << endl;
        cout << "5. Show wallet info" << endl;
        cout << "6. Compare two wallets" << endl;
        cout << "7. Simulate market [using-->(++, --)]" << endl;
        cout << "8. Access transaction by index" << endl;
        cout << "9. Mine coins (recursive based)" << endl;
        cout << "10. Show Exchange Info" << endl;
        cout << "11. Update Exchange Rate (admin only)" << endl;
        cout << "12. Show transaction history" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        // create new wallet
        case 1:
        {
            if (walletCount < 10)
            {
                char name[50];
                cout << "Enter owner name: ";
                cin >> name;
                wallets[walletCount++] = new Wallet(name);
                cout << "Wallet created successfully!" << endl;
            }
            else
            {
                cout << "Maximum wallet limit reached!" << endl;
            }
            break;
        }
        // to deposit btc in wallet
        case 2:
        {
            int index;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                float amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                *wallets[index] += amount;
                cout << amount << " btc Deposited Successfully" << endl;
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // to withdraw btc
        case 3:
        {
            int index;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                float amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                *wallets[index] -= amount;
                cout << amount << " btc Withdraw Successfully" << endl;
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // to transfer btc from 1 wallet to other
        case 4:
        {
            int fromIndex, toIndex;
            cout << "Enter source wallet index (0-9): ";
            cin >> fromIndex;
            cout << "Enter destination wallet index (0-9): ";
            cin >> toIndex;
            if (fromIndex >= 0 && fromIndex < walletCount && wallets[fromIndex] &&
                toIndex >= 0 && toIndex < walletCount && wallets[toIndex])
            {
                *wallets[fromIndex] >> *wallets[toIndex];
            }
            else
            {
                cout << "Invalid wallet indices!" << endl;
            }
            break;
        }
        // to show wallet info
        case 5:
        {
            int index;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                wallets[index]->showWalletInfo();
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // to check which wallet has more btc
        case 6:
        {
            int index1, index2;
            cout << "Enter first wallet index (0-9): ";
            cin >> index1;
            cout << "Enter second wallet index (0-9): ";
            cin >> index2;
            if (index1 >= 0 && index1 < walletCount && wallets[index1] &&
                index2 >= 0 && index2 < walletCount && wallets[index2])
            {
                if (*wallets[index1] > *wallets[index2])
                {
                    cout << "Wallet " << index1 << " has a higher balance." << endl;
                }
                else if (*wallets[index1] < *wallets[index2])
                {
                    cout << "Wallet " << index2 << " has a higher balance." << endl;
                }
                else
                {
                    cout << "Both wallets have the same balance." << endl;
                }
            }
            else
            {
                cout << "Invalid wallet indices!" << endl;
            }
            break;
        }
        // to increment or decrement btc in wallet
        case 7:
        {
            int index, choice;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                cout << "1. Increment (++)" << endl;
                cout << "2. Decrement (--)" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    ++(*wallets[index]);
                    cout << "Wallet balance incremented." << endl;
                }
                else if (choice == 2)
                {
                    --(*wallets[index]);
                    cout << "Wallet balance decremented." << endl;
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // to check wallets transaction by index
        case 8:
        {
            int index, transactionIndex;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                cout << "Enter transaction index: ";
                cin >> transactionIndex;
                cout << "Transaction: " << (*wallets[index])[transactionIndex] << " BTC" << endl;
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // to perform recursive mining
        case 9:
        {
            int index;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                wallets[index]->performMining();
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // to show exchange info
        case 10:
        {
            Exchange::showExchangeInfo();
            break;
        }
        // to update new exchange rates
        case 11:
        {
            float newRate;
            cout << "Enter new exchange rate: ";
            cin >> newRate;
            updateExchangeRate(newRate);
            break;
        }
        // to check complete transaction history of the wallet
        case 12:
        {
            int index;
            cout << "Enter wallet index (0-9): ";
            cin >> index;
            if (index >= 0 && index < walletCount && wallets[index])
            {
                wallets[index]->showTransactionHistory();
            }
            else
            {
                cout << "Invalid wallet index!" << endl;
            }
            break;
        }
        // exit the program
        case 0:
            cout << "Thank You for using BlockVerse....." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    // free the memory
    for (int i = 0; i < walletCount; ++i)
    {
        delete wallets[i];
    }
}

int main()
{
    // random time
    srand(time(0));
    showMenu();
    return 0;
}