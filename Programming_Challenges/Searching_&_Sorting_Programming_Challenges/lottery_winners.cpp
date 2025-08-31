#include <iostream>
using namespace std;

bool checkWin(int[], int, int);

int main()
{
    int input;
    const int size = 10;
    int winNumbers[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

    cout << "Enter your lottery Number: " << endl;
    cin >> input;

    if (checkWin(winNumbers, size, input))
    {
        cout << "Congrats!!!\nYou have won the lottery" << endl;
    }
    else
    {
        cout << "No win!" << endl;
    }

    return 0;
}

bool checkWin(int arr[], int size, int val)
{
    int first = 0;
    int last = size - 1;
    int mid;
    bool found = false;
    while (!found && first <= last)
    {
        int middle = (first + last) / 2;
        if (arr[middle] == val)
        {
            return true;
        }
        else if (arr[middle] > val)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return false;
}
