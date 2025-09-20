#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class LoginSignUpSystem
{
private:
    int id;
    string name;
    string password;

public:
    LoginSignUpSystem(int i = 0, string n = "", string p = "")
    {
        id = i;
        name = n;
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
            cout << "Enter your name: " << endl;
            getline(cin, n);
            name = n;
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