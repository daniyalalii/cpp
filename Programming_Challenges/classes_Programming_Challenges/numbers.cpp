#include <iostream>
using namespace std;

class numbers
{
private:
    int n;
    string lessthan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = "hundred";
    string thousand = "thousand";

public:
    numbers() {};
    void getNum()
    {
        int num;
        do
        {
            cout << "Enter the number (must be positive): " << endl;
            cin >> num;
        } while (num < 0);
        n = num;
    }
    void print()
    {
        if (n < 20)
        {
            cout << lessthan20[n] << endl;
        }
        else if (n < 100)
        {
            cout << tens[n / 10];
            if (n % 10 != 0)
                cout << " " << lessthan20[n % 10];
            cout << endl;
        }
        else if (n < 1000)
        {
            cout << lessthan20[n / 100] << " " << hundred;
            if (n % 100 != 0)
            {
                cout << " ";
                if (n % 100 < 20)
                    cout << lessthan20[n % 100];
                else
                {
                    cout << tens[(n % 100) / 10];
                    if (n % 10 != 0)
                        cout << " " << lessthan20[n % 10];
                }
            }
            cout << endl;
        }
        else
        {
            cout << lessthan20[n / 1000] << " " << thousand;
            if (n % 1000 != 0)
            {
                cout << " ";
                int rem = n % 1000;
                cout << lessthan20[rem / 100] << " " << hundred;
                if (rem % 100 != 0)
                {
                    cout << " ";
                    if (rem % 100 < 20)
                        cout << lessthan20[rem % 100];
                    else
                    {
                        cout << tens[(rem % 100) / 10];
                        if (rem % 10 != 0)
                            cout << " " << lessthan20[rem % 10];
                    }
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    numbers n;
    n.getNum();
    n.print();
    return 0;
}