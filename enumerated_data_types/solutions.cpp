#include <iostream>
using namespace std;

enum Flower
{
    ROSE,
    DAISY,
    PETUNIA
};
// it will display 0,1,2 in memory

enum
{
    HOBBIT,
    ELF = 7,
    DRAGON
};
// 11.23--> it is anonymous enum type

enum Letters
{
    Z,
    Y,
    X
};
int main()
{
    // cout<<ROSE;
    cout << HOBBIT << " " << ELF << " " << DRAGON << endl;
    /*
    It will display these values as they are changed
    HOBBIT-->0
    ELF-->7
    DRAGON-->0
    */
    if (Z > X)
        cout << "Z is greater than X. \n"; // this will not be printed
    else
        cout << "Z is not greater than X. \n"; // this will be printed
    return 0;
}