#include <iostream>
using namespace std;

int main()
{
    int count;
    count = 10;
    cout<<"Address of count is: "<<&count<<endl;
    int *ptr = &count;
    cout<<"Address using pointer: "<<ptr;
    return 0;
}