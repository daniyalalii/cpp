#include <iostream>
using namespace std;

int *allocateArray(int size)
{
    int *ptr = new int [size];
    return ptr;
}
int main()
{
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    int *arr = allocateArray(size); 

    //free memory
    delete[] arr;
    return 0;
}
