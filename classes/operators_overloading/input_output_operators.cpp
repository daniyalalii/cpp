#include <iostream>
using namespace std;

class rect
{
private:
    int length;
    int width;

public:
    rect(int l = 0, int w = 0)
    {
        length = l;
        width = w;
    }
    friend ostream &operator<<(ostream &out, rect &temp)
    {
        out << "Length: " << temp.length << endl;
        out << "Width: " << temp.width << endl;
        return out;
    }
    friend istream &operator>>(istream &in, rect &temp)
    {
        cout << "Enter the length: ";
        in >> temp.length;
        cout << "Enter the width: ";
        in >> temp.width;
        return in;
    }
};

int main()
{
    rect r1;
    cin >> r1;
    cout << endl;
    cout << r1;
    return 0;
}