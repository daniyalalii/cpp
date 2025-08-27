#include <iostream>
using namespace std;
int main()
{
    const int size = 100;
    int *ip = new int[size];
    for (int i = 0; i < size; i++)
    {
        ip[i] = i + 1;
    }
    for (int i = 0; i < size; i++)
    {
        cout << ip[i] << " ";
    }
    delete[] ip;
    return 0;
}