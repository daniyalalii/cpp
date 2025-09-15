#include <iostream>
using namespace std;
class Sky
{
public:
    Sky()
    {
        cout << "Entering the sky.\n";
    }
    Sky(string color)
    {
        cout << "The sky is " << color << endl;
    }
    ~Sky()
    {
        cout << "Leaving the sky.\n";
    }
};
class Ground : public Sky
{
public:
    Ground()
    {
        cout << "Entering the Ground.\n";
    }
    Ground(string c1, string c2) : Sky(c1)
    {
        cout << "The ground is " << c2 << endl;
    }
    ~Ground()
    {
        cout << "Leaving the Ground.\n";
    }
};
int main()
{
    Ground object("blue", "green");
    return 0;
}