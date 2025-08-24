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

Rectangle newinputRectangle()
{
    Rectangle rect;
    cout << "Enter Length: ";
    cin >> rect.length;
    cout << "Enter Width: ";
    cin >> rect.width;
    return rect;
}


int main()
{
    Rectangle myRect{10, 5};
    Rectangle *ptr = &myRect;
    displayRectangle(*ptr);
    // Rectangle myRect{10, 5};
    // Rectangle myRect;
    // inputRectangle(myRect);
    // newinputRectangle();
    // myRect = newinputRectangle();
    // displayRectangle(myRect);
    return 0;
}

//11.15
// Assume rptr is a pointer to a Rectangle structure. Which of the expressions, A,
// B, or C, is equivalent to the following expression:
// rptr->width
// A) *rptr.width
// B) (*rptr).width
// C) rptr.(*width)
// Answer: B
