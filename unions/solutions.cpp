#include <iostream>
using namespace std;

union ThreeTypes
{
    char letter;
    int whole;
    double real;
};

int main()
{
    const int size = 50;
    ThreeTypes t1[size];

    for (int i = 0; i < size; i++)
    {
        t1[i].whole = 2.37;
    }
    
    return 0;
}