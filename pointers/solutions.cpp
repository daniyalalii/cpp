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

/*
List three uses of the * symbol in C++
1- used in multiplying the numbers: 
    2*2 = 4
2- use for pointers to point a variable's memory address:
    int num;
    int *ptr = & num;
3- use for derefrencing the value inside pointer;
    (like in above case if num contains value 10, then)
    num = 10;
    cout<<*ptr;
    it will print 10, the value of num, as ptr points to address of num.    
*/