#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    void getDate() const
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date d1;
    int day, month, year;
    cout << "Enter date: " << endl;
    cin >> day;
    d1.setDay(day);
    cout << "Enter month: " << endl;
    cin >> month;
    d1.setMonth(month);
    cout << "Enter year: " << endl;
    cin >> year;
    d1.setYear(year);
    cout << "Date is: " << endl;
    d1.getDate();

    return 0;
}