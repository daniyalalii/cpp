#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    string number;
    string hireDate;

public:
    Employee(string n = "", string num = "", string date = "")
    {
        name = n;
        number = num;
        hireDate = date;
    }
    void getData()
    {
        cout << "---------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
        cout << "Hiring Date: " << hireDate << endl;
    }
    void setName(string Name)
    {
        name = Name;
    }
    void setNumber(string num)
    {
        number = num;
    }
    void setDate(string date)
    {
        hireDate = date;
    }
};

class ProductionWorker : public Employee
{
private:
    int shift;
    double payRate;

public:
    ProductionWorker() : Employee("", "", ""), shift(1), payRate(0.0) {}

    ProductionWorker(string Name, string num, string date, int s, double rate) : Employee(Name, num, date)
    {
        shift = s;
        payRate = rate;
    }

    int getShift() const
    {
        return shift;
    }

    double getPayRate() const
    {
        return payRate;
    }

    void setShift(int s)
    {
        shift = s;
    }

    void setPayRate(double rate)
    {
        payRate = rate;
    }

    void getWorkerData()
    {
        getData();
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Pay Rate: $" << payRate << endl;
        cout << "---------------------------------" << endl;
    }
};
int main()
{
    ProductionWorker worker1;
    string name, number, date;
    int shift;
    double rate;
    cout << "Enter your name: " << endl;
    getline(cin, name);
    worker1.setName(name);
    cout << "Enter your Number" << endl;
    getline(cin, number);
    worker1.setNumber(number);
    cout << "Enter your hiring date" << endl;
    getline(cin, date);
    worker1.setDate(date);
    cout << "Enter your shift 1 for Day, 0 for night" << endl;
    cin >> shift;
    worker1.setShift(shift);
    cout << "Enter your Hourly pay rate: " << endl;
    cin >> rate;
    worker1.setPayRate(rate);
    worker1.getWorkerData();
    return 0;
}