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
    rect operator+(rect &other)
    {
        rect temp;
        temp.length = length + other.length;
        temp.width = width + other.width;
        return temp;
    }
    const rect operator-(rect other)
    {
        rect temp;
        temp.length = length - other.length;
        temp.width = width - other.width;
        return temp;
    }
};
int main()
{
    rect r1(12, 15);
    rect r2(12, 15);
    rect r3;

    r3 = r1 + r2;
    cout << "After Addition\n";
    r3.display();
    r3 = r1 - r2;
    cout << "After substraction\n";
    r3.display();
    return 0;
}