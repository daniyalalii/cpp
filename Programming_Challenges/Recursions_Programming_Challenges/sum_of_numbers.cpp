#include <iostream>
using namespace std;

int sum(int a, int b)
{
    if (b == a)
    {
        return a;
    }
    return b + sum(a, b + 1);
}

int main()
{
    int input;
    cout << "Enter a number for sum: " << endl;
    cin >> input;
    cout << "Sum upto that number is: ";
    cout << sum(input, 0);
    return 0;
}