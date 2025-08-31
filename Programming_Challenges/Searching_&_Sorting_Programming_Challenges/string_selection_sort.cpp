#include <iostream>
#include <string>
using namespace std;

void showNames(const string names[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << endl;
    }
}

void SelectionSort(string names[], int size)
{
    int startScan, minIndex;
    string minValue;

    for (startScan = 0; startScan < size - 1; startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

int main()
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth"};

    // Insert your code to complete this program
    cout << "Before sorting" << endl;
    showNames(names, NUM_NAMES);
    SelectionSort(names, NUM_NAMES);
    cout << "After sorting" << endl;
    showNames(names, NUM_NAMES);
    return 0;
}