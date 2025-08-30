#include <iostream>
using namespace std;

long int RecursivePower(int a, int b, int start = 0)
{
    if (start == b)
    {
        return 1;
    }
    else
    {
        return a * RecursivePower(a, b, start + 1);
    }
}

int main()
{
    int num, exp;
    cout << "Enter a number and exponent" << endl;
    cin >> num >> exp;
    cout << "Answer: ";
    cout << RecursivePower(num, exp);
    return 0;
}