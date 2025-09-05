#include <iostream>
using namespace std;

class rect
{
private:
    int length;
    int width;

public:
    rect()
    {
        length = 0;
        width = 0;
    }
    rect(int l, int w)
    {
        length = l;
        width = w;
    }
    void display()
    {
        cout << "-------------------------------" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "-------------------------------" << endl;
    }
    bool operator<(rect &other)
    {
        bool res = false;
        if (length < other.length)
        {
            res = true;
        }
        return res;
    }
    bool operator>(rect &other)
    {
        bool res = false;
        if (length > other.length)
        {
            res = true;
        }
        return res;
    }
    bool operator==(rect &other)
    {
        bool res = false;
        if (length == other.length)
        {
            res = true;
        }
        return res;
    }
};
int main()
{
    rect r1(1, 2);
    rect r2(2, 4);
    if (r1 > r2)
    {
        cout << "Length of r1 is greater than r2" << endl;
    }
    else
    {
        cout << "Lenght of r2 is greater than r1" << endl;
    }
    if (r1 < r2)
    {
        cout << "Length of r1 is smaller than r2" << endl;
    }
    else
    {
        cout << "Lenght of r2 is smaller than r1" << endl;
    }

    rect r3(1, 2);
    if (r1 == r3)
    {
        cout << "Length of r1 and r3 are equal" << endl;
    }
    else
    {
        cout << "Length of r1 and r3 are not equal" << endl;
    }

    return 0;
}