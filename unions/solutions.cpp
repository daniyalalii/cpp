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
    
    return 0;
}