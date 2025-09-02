#include <iostream>
#include <iomanip>
using namespace std;

class numberArray
{
private:
    int size;
    float *ptr;

public:
    numberArray(int n)
    {
        size = n;
        ptr = new float[size];
    }

    void setData()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the data for element number: " << i + 1 << endl;
            cin >> ptr[i];
        }
    }
    void getData()
    {
        cout << "-----------------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << fixed << showpoint << setprecision(2);
            cout << ptr[i] << " " << endl;
        }
        cout << "-----------------------------" << endl;
    }
    float highValue()
    {
        float high = ptr[0];
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] > high)
            {
                high = ptr[i];
            }
        }
        return high;
    }
    float lowValue()
    {
        float low = ptr[0];
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] < low)
            {
                low = ptr[i];
            }
        }
        return low;
    }
    float average()
    {
        float sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + ptr[i];
        }
        float avg = sum / size;
        return avg;
    }
    ~numberArray()
    {
        delete[] ptr;
        ptr = nullptr;
    }
};

int main()
{
    numberArray num1(5);
    num1.setData();
    num1.getData();
    cout << "Highest Value: " << num1.highValue() << endl;
    cout << "Lowest Value: " << num1.lowValue() << endl;
    cout << "Average: " << num1.average() << endl;
    return 0;
}