#include <iostream>
using namespace std;

bool ismember(int arr[], int size, int num, int start)
{
    if (start >= size)
    {
        return false;
    }
    if (arr[start] == num)
    {
        return true;
    }
    return ismember(arr, size, num, start + 1);
}

int main()
{
    const int size = 5;
    int val;
    int arr[size] = {12, 32, 23, 12, 43};

    cout << "Enter the number you want to find: " << endl;
    cin >> val;

    bool isPresent = ismember(arr, size, val, 0);
    if (isPresent)
    {
        cout << "Number is present in array!" << endl;
    }
    else
    {
        cout << "Number is not present in the array!" << endl;
    }
    return 0;
}