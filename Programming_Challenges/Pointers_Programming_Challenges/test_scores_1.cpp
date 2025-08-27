#include <iostream>
#include <iomanip>
using namespace std;

void sortArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

double calculateAvg(int *arr, int size)
{
    double sum = 0.0;
    double average;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    average = sum / size;
    return average;
}

void output(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int size;
    cout << "Enter the total tests that you completed:(size) " << endl;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << "Enter the test score for test: " << i + 1 << endl;
            cin >> arr[i];
        } while (arr[i] < 0);
    }

    sortArr(arr, size);

    output(arr, size);

    double average = calculateAvg(arr, size);

    cout << fixed << showpoint << setprecision(2);

    cout << "Average: " << average << endl;

    return 0;
}