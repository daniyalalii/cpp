#include <iostream>
using namespace std;
int main()
{

    int *ip = new int(12);
    cout<<"Value: "<<*ip;
    delete ip;
    ip = nullptr;
    return 0;
}