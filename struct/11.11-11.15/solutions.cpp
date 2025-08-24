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

int main()
{
    Rectangle myRect{10, 5};
    displayRectangle(myRect);
    return 0;
}