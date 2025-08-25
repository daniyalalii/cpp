#include <iostream>
using namespace std;

const int QuarterSize = 4;
struct CompanyDetails
{
    string DivisionName;
    double QuarterSales[QuarterSize];
    double TotalAvenueSales;
    double AvgQuarterlySales;
};

void inputData(CompanyDetails &c)
{
    cout << "--------------" << endl;
    cout << "Enter Division Name: (North, East, West, South)" << endl;
    cin >> c.DivisionName;
    for (int i = 0; i < QuarterSize; i++)
    {
        do
        {
            cout << "Enter Sales for " << i + 1 << " Quarter: " << endl;
            cin >> c.QuarterSales[i];
        } while (c.QuarterSales[i] < 0);
    }
    do
    {
        cout << "Enter Total Avenue Sales: " << endl;
        cin >> c.TotalAvenueSales;
    } while (c.TotalAvenueSales < 0);
    cout << "--------------" << endl;
}

void showData(CompanyDetails &c)
{
    cout << "---------------" << endl;
    cout << "Division Name: " << c.DivisionName << endl;
    for (int i = 0; i < QuarterSize; i++)
    {
        cout << "Sale for " << i + 1 << " quarter is: " << c.QuarterSales[i] << endl;
        c.AvgQuarterlySales += c.QuarterSales[i];
    }
    cout << "Average Quarter Sales: " << (c.AvgQuarterlySales) / QuarterSize << endl;
    cout << "Total Anual Sales: " << c.TotalAvenueSales << endl;
    cout << "---------------" << endl;
}

int main()
{
    CompanyDetails c1, c2, c3, c4;
    inputData(c1);
    inputData(c2);
    inputData(c3);
    inputData(c4);
    showData(c1);
    showData(c2);
    showData(c3);
    showData(c4);

    return 0;
}