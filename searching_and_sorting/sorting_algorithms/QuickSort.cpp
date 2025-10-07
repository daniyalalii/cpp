#include <iostream>
using namespace std;

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    QuickSort(arr, 0, n - 1);
    cout << "After: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}