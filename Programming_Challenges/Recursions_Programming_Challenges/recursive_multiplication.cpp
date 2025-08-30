#include <iostream>
using namespace std;

long int RecursiveMultiplication(int a, int b){
    if(b==0){
        return 0;
    }
    return a + RecursiveMultiplication(a,b-1);
}

int main()
{
    int x, y;
    cout << "Enter the value of x and y: " << endl;
    cin >> x >> y;

    cout<<"Multiplication: "<<RecursiveMultiplication(x,y) <<endl;
    return 0;
}