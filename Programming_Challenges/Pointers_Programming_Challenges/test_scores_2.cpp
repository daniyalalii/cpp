#include <iostream>
#include <iomanip>
using namespace std;

void sortArr(int *arr, int size, string str[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int tempScore = arr[j];
                arr[j] = arr[i];
                arr[i] = tempScore;

                string tempName = str[j];
                str[j] = str[i];
                str[i] = tempName;
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

void output(int *arr, int size, string str[])
{
    for (int i = 0; i < size; i++)
    {
        cout << str[i]<<": ";
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the total tests that you completed:(size) " << endl;
    cin >> size;

    int *arr = new int[size];
    string *strArr = new string[size];

    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << "Enter name of the student: " << i + 1 << endl;
            cin >> strArr[i];
            cout << "Enter the test score for test: " << i + 1 << endl;
            cin >> arr[i];
        } while (arr[i] < 0);
    }

    sortArr(arr, size, strArr);

    cout<<"Ouput: "<<endl;
    output(arr, size, strArr);

    double average = calculateAvg(arr, size);

    cout << fixed << showpoint << setprecision(2);

    cout << "Average: " << average << endl;

    delete[] arr;
    delete[] strArr;
    return 0;
}