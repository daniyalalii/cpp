// #include<iostream>
// using namespace std;
// void *pointerReturn(int *);
// int main(){
//     int value = 10;
//     pointerReturn(&value);
//     cout<<"After Function call: "<<value<<endl;
//     return 0;
// }
// void *pointerReturn(int *ptr){
//     *ptr = 12;
//     return ptr;
// }


//-----------------------------
//9.17

#include<iostream>
using namespace std;
void *pointerReturn(int );
int main(){
    int value = 10;
    // pointerReturn(&value);
    cout<<"After Function call: "<<value<<endl;
    return 0;
}
void *pointerReturn(int ptr){
    ptr = 12;
    // return ptr; 
}
// this is the wrong way and it will give error