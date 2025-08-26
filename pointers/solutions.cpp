#include <iostream>
using namespace std;

int main()
{
    // int count;
    // count = 10;
    // cout<<"Address of count is: "<<&count<<endl;
    // int *ptr = &count;
    // cout<<"Address using pointer: "<<ptr;

    // float number = 10.2;
    // float *fltptr = &number;
    // cout<<"Value inside float ptr: "<<*fltptr<<endl;
    // const int size = 10;
    // int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int *ptr = arr;
    // for (int x = 0; x < 10; x++)
    // {
    //     cout << *(ptr + x)<<" ";
    // }

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

/*
Code:
int x = 50, y = 60, z = 70;
int *ptr = nullptr;
cout << x << " " << y << " " << z << endl;
ptr = &x;
*ptr *= 10;
ptr = &y;
*ptr *= 5;
ptr = &z;
*ptr *= 2;
cout << x << " " << y << " " << z << endl;
Output:
(first cout will print this)
50 60 70
(then pointer is pointing to x address,
value inside x is multiplied by 10, x-->500
then pointer addresses to y
value inside y is multiplied with 5, y-->300
then pointer points to address z
value inside z is multiplied with 2, z-->140
then the last cout prints value of updated x,y and z
)
500 300 140
*/

/*
if pointer is pointing to memory address 12000
then this line will point to, 
ptr += 10;
answer: 12040
*/