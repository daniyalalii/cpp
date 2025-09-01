#include <iostream>
using namespace std;
class Yard
{
private:
    int length, width;

public:
    Yard()
    {
        length = 0;
        width = 0;
    }
    void setLength(int len)
    {
        length = len;
    }
    void setWidth(int w)
    {
        width = w;
    }
};
int main()
{
    // Finish this program
    const int size = 5;
    int length, width;
    Yard arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the length for yard: " << i + 1 << endl;
        cin >> length;
        arr[i].setLength(length);
        cout << "Enter width for yard: " << i + 1 << endl;
        cin >> width;
        arr[i].setWidth(width);
    }
}