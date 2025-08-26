#include <iostream>
using namespace std;

int main()
{
    // int count;
    // count = 10;
    // cout<<"Address of count is: "<<&count<<endl;
    // int *ptr = &count;
    // cout<<"Address using pointer: "<<ptr;

    float number = 10.2;
    float *fltptr = &number;
    cout<<"Value inside float ptr: "<<*fltptr<<endl;
    return 0;
}