#include <iostream>
using namespace std;

void reverse(string str, int length, int pos)
{
    if (pos <= length)
    {
        reverse(str, length, pos + 1);
        cout << str[pos];
    }
}

int main()
{
    string str = "I am a Boy";
    int size = str.size();
    cout << "Reverse string: " << endl;
    reverse(str, size, 0);
    return 0;
}