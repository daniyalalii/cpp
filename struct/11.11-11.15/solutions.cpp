#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int width;
};

void displayRectangle(const Rectangle &rect)
{
    cout << "Length: " << rect.length << endl;
    cout << "Width: " << rect.width << endl;
}

void inputRectangle(Rectangle &rect)
{
    cout << "Enter Length: ";
    cin >> rect.length;
    cout << "Enter Width: ";
    cin >> rect.width;
}

int main()
{
    // Rectangle myRect{10, 5};
    Rectangle myRect;
    inputRectangle(myRect);
    displayRectangle(myRect);
    return 0;
}