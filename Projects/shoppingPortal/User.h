#ifndef USER_H
#define USER_H
#include "./loginSignup.h"

class User : public LoginSignUpSystem
{
private:
    int userID;
    int phoneNumber;
    string name;
    string email;
    string password;
    string address;

public:
    User(int id = 0, int number = 0, string n = "", string em = "", string pass = "", string addr = "")
    {
        userID = id;
        phoneNumber = number;
        name = n;
        email = em;
        password = pass;
        address = addr;
    }
    virtual void login(int choice)
    {
        if (choice == 1)
        {
            LoginSignUpSystem::setLogin(true);
        }
        else
        {
            cout << "Error occured!" << endl;
        }
    }
    virtual void logout()
    {
        cout << "Logged out successfully!" << endl;
    }
    virtual void displayInfo()
    {
        cout << "==================================" << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Password: " << password << endl;
        cout << "User Id: " << userID << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
    }
};

#endif