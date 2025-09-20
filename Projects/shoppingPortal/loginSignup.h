#ifndef LOGIN_SIGNUP_H
#define LOGIN_SIGNUP_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class LoginSignUpSystem
{
private:
    int id;
    string email;
    string password;

public:
    LoginSignUpSystem(int i = 0, string n = "", string p = "")
    {
        id = i;
        email = n;
        password = p;
    }
    void setLogin(bool login)
    {
        if (login)
        {
            string n, pass;
            int key;
            cout << "===================================" << endl;
            cout << "Enter your ID" << endl;
            cin >> key;
            id = key;
            cin.ignore();
            cout << "Enter your Email: " << endl;
            getline(cin, n);
            email = n;
            cout << "Enter your Password: " << endl;
            getline(cin, pass);
            password = pass;
            cout << "You have successfully registered" << endl;
        }
    }
    bool getLogin(LoginSignUpSystem &other)
    {
        if (id == other.id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif