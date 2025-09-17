#include <iostream>
#include <string>
using namespace std;

class PersonData
{
private:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;

public:
    PersonData(string fname = "", string lname = "", string addr = "", string c = "", string st = "", string z = "", string number = "")
    {
        firstName = fname;
        lastName = lname;
        address = addr;
        city = c;
        state = st;
        zip = z;
        phoneNumber = number;
    }
    void getPersonData() const
    {
        cout << "--------------------------------" << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Address: " << address << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "zip: " << zip << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }
};
class CustomerData : public PersonData
{
private:
    string customerNumber;
    bool mailingList;

public:
    CustomerData(string fname = "", string lname = "", string addr = "", string c = "", string st = "", string z = "", string number = "", string cNumber = "", bool list = false) : PersonData(fname, lname, addr, c, st, z, number)
    {
        customerNumber = cNumber;
        mailingList = list;
    }
    void getCustomerData()
    {
        getPersonData();
        cout << "Customer Number:  " << customerNumber << endl;
        cout << "Mailing List: " << (mailingList ? "Yes" : "No") << endl;
        cout << "------------------------------------------" << endl;
    }
};
int main()
{
    CustomerData customer1("Phill", "Salt", "London Street 146", "London", "England", "00000", "123456789", "SA123", true);
    customer1.getCustomerData();
    return 0;
}