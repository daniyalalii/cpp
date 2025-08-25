#include<iostream>
using namespace std;

enum Flower { ROSE, DAISY, PETUNIA };
// it will display 0,1,2 in memory

enum { HOBBIT, ELF = 7, DRAGON };
// 11.23--> it is anonymous enum type

int main(){
    // cout<<ROSE;
    cout << HOBBIT << " " << ELF << " " << DRAGON << endl;
    /*
    It will display these values as they are changed
    HOBBIT-->0
    ELF-->7
    DRAGON-->0
    */
    return 0;
}