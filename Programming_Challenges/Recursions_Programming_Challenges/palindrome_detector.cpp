#include <iostream>
using namespace std;

bool isPalindrome(string str, int length, int start, int end)
{
    if (start >= length)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return isPalindrome(str, length, start + 1, end - 1);
}

int main()
{
    string str = "kayak";
    int size = str.size();
    if (isPalindrome(str, size, 0, size - 1))
    {
        cout << "It is a Palindrome" << endl;
    }
    else
    {
        cout << "It is not a Palindrome" << endl;
    }
    return 0;
}