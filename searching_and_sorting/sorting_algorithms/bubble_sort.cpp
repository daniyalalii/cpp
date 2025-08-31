#include <iostream>
using namespace std;

void BubbleSort(int[], int);
void ShowOutput(int[], int);

int main()
{
    const int size = 10;
    int arr[size] = {10, 3, 2, 4, 6, 1, 5, 7, 9, 8};
    cout << "Before Bubble Sort: " << endl;
    ShowOutput(arr, size);
    BubbleSort(arr, size);
    cout << "After Bubble Sort: " << endl;
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

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}