#include <iostream>
using namespace std;
class First
{
protected:
    int a;

public:
    First(int x = 1)
    {
        a = x;
    }
    void twist()
    {
        a *= 2;
    }
    int getVal()
    {
        twist();
        return a;
    }
};
class Second : public First
{
private:
    int b;

public:
    Second(int y = 5)
    {
        b = y;
    }
    void twist()
    {
        b *= 10;
    }
};
int main()
{
    First object1;
    Second object2;
    cout << object1.getVal() << endl;
    cout << object2.getVal() << endl;
    return 0;
}