#include <iostream>
using namespace std;

int main()
{
    int input;
    int factorial = 1;
    do
    {
        cout << "Enter a number to find the factorial:(must be positive) " << endl;
        cin >> input;
    } while (input < 0);
    if(input == 0){
        factorial = 1;
    }
    else{
        for(int i =input;i>=1;i--){
            factorial = factorial *i;
        }
    }

    cout<<"Factorial: "<<factorial<<endl;
    return 0;
}