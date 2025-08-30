#include <iostream>
using namespace std;

int AckermannsFunction(int a, int b){
    if(a == 0){
        return b+1;
    }
    if(b==0){
        return AckermannsFunction(a-1,1);
    }
    else{
        return AckermannsFunction(a-1,AckermannsFunction(a,b-1));
    }
}

int main()
{
    cout<<AckermannsFunction(0,0)<<endl;
    cout<<AckermannsFunction(0,1)<<endl;
    cout<<AckermannsFunction(1,1)<<endl;
    cout<<AckermannsFunction(1,2)<<endl;
    cout<<AckermannsFunction(1,3)<<endl;
    cout<<AckermannsFunction(2,2)<<endl;
    cout<<AckermannsFunction(3,2)<<endl;


    return 0;
}