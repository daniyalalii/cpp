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
        t1[i].letter = 'A';
        t1[i].real = 10;
    }

        for (int i = 0; i < size; i++)
    {
        cout<<t1[i].whole<<endl;
        cout<<t1[i].letter<<endl;
        cout<<t1[i].real<<endl; 
    }
    
    return 0;
}

// the answer will show 0 and 10 only because unions overwrite the previous data because of storing all the memory address as the largest of its member