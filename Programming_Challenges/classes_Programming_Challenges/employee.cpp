#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Employee
{
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    Employee()
    {
        name = " ";
        idNumber = 0;
        department = " ";
        position = " ";
    }
    Employee(string n, int idNum, string dep, string pos)
    {
        name = n;
        idNumber = idNum;
        department = dep;
        position = pos;
    }
    Employee(string n, int idNum)
    {
        name = n;
        idNumber = idNum;
        department = " ";
        position = " ";
    }

    void setDetails()
    {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter ID Number: ";
        cin >> idNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Position: ";
        getline(cin, position);
    }
    void getDetails()
    {
        cout << "Name: " << name << endl;
        cout << "ID Number: " << idNumber << endl;
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
    }
};
int main()
{
    Employee emp1("Susan Meyers", 47889);
    Employee emp2("Mark Jones", 39119, "IT", "Programming");
    Employee emp3;

    emp3.setDetails();
    cout << "-----------------------------------------------------" << endl;
    cout << "Details for employee 1: " << endl;
    emp1.getDetails();
    cout << "-----------------------------------------------------" << endl;
    cout << "Details for employee 2: " << endl;
    emp2.getDetails();
    cout << "-----------------------------------------------------" << endl;
    cout << "Details for employee 3: " << endl;
    emp3.getDetails();
    cout << "-----------------------------------------------------" << endl;

    return 0;
}