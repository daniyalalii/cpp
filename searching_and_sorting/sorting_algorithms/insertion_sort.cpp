#include <iostream>
using namespace std;

void insertionSort(int arr[], int s)
{
    for (int i = 1; i < s; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int arr[] = {9, 8, 1, 3, 2, 5, 7, 6, 4};
    cout << "Before: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    cout << "After: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}