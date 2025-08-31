#include <iostream>
using namespace std;

void SelectionSort(int[], int);
void ShowOutput(int[], int);

int main()
{
    const int size = 10;
    int arr[size] = {10, 3, 2, 4, 6, 1, 5, 7, 9, 8};
    cout << "Before Selection Sort: " << endl;
    ShowOutput(arr, size);
    SelectionSort(arr, size);
    cout << "After Selection Sort: " << endl;
    ShowOutput(arr, size);
    return 0;
}

void ShowOutput(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minValue = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < minValue)
            {
                minValue = arr[j];
                minIndex = j;
            }
        }
        arr[minIndex] = arr[i];
        arr[i] = minValue;
    }
}