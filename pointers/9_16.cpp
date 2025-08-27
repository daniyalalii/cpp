#include<iostream>
using namespace std;
void *pointerReturn(int *);
int main(){
    int value = 10;
    pointerReturn(&value);
    cout<<"After Function call: "<<value<<endl;
    return 0;
}
void *pointerReturn(int *ptr){
    *ptr = 12;
    return ptr;
}