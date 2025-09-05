#include <iostream>
using namespace std;

class parent
{
private:
    string name;
    int age;
    int familyMembers;

public:
    parent()
    {
        name = "";
        age = 0;
        familyMembers = 0;
    }
    parent(string n, int a, int fm)
    {
        name = n;
        age = a;
        familyMembers = fm;
    }
    void displaydata()
    {
        cout << "--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Family Members: " << familyMembers << endl;
    }

    const parent operator=(const parent &data)
    {
        name = data.name;
        age = data.age;
        familyMembers = data.familyMembers;
        return *this;
    }
};

int main()
{
    parent p1("Ali", 12, 4);
    parent p2;
    parent p3;
    p1.displaydata();
    p2 = p1;
    p2.displaydata();
    p3.displaydata();
    return 0;
}