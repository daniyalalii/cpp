#include <iostream>
using namespace std;

void sign(int n)
{
    if (n <= 0)
    {
        return;
    }
    else
    {
        cout << "No Parking\n";
        sign(n - 1);
    }
}
int main()
{
    int input;
    cout<<"Enter a value: "<<endl;
    cin>>input;
    sign(input);
    return 0;
}