#include <iostream>
using namespace std;

class area
{
private:
    int length;

public:
    area(int l = 0)
    {
        length = l;
    }
    void display()
    {
        cout << "----------------" << endl;
        cout << "Length: " << length << endl;
    }
    area operator++()
    {
        length++;
        return *this;
    }
    area operator++(int)
    {
        area temp(length);
        length++;
        return temp;
    }
    area operator--()
    {
        length--;
        return *this;
    }
    area operator--(int)
    {
        area temp(length);
        length--;
        return temp;
    }
};
int main()
{
    area a1(20);
    a1.display();
    a1++;
    a1.display();
    ++a1;
    a1.display();
    a1--;
    a1.display();
}