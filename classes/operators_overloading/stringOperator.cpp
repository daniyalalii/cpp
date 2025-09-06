// overloading the [] operator
#include <iostream>
using namespace std;

class numList
{
private:
    int size;
    int *list;

public:
    numList(int s)
    {
        size = s;
        list = new int[size];
        for (int i = 0; i < size; i++)
        {
            list[i] = i + 1; // or *(list + i) = i+1;
        }
    }
    // copy constructor
    numList(const numList &other)
    {
        size = other.size;
        list = new int[size];
        for (int i = 0; i < size; i++)
        {
            list[i] = other.list[i];
        }
    }
    int &operator[](const int data)
    {
        if (data < 0 || data >= size)
        {
            cout << "Error, Out of bound size ";
            static int dummy = -1;
            return dummy;
        }
        return list[data];
    }
    ~numList()
    {
        delete[] list;
    }
};
int main()
{
    const int size = 5;
    numList l1(size);
    for (int i = 0; i < size; i++)
    {
        cout << l1[i] << " ";
    }
    cout << endl;
    cout << l1[size + 1];
    return 0;
}