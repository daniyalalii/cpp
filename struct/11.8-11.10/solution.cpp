// use questions.md for reference
#include <iostream>
using namespace std;

struct Measurement
{
    int miles;
    long int meters;
};

struct Destination
{
    string city;
    Measurement distance;
};
int main()
{
    Destination d1;
    d1.city = "Tupelo";
    d1.distance.miles = 375;
    d1.distance.meters = 603375;

    cout << "City: " << d1.city << endl;
    cout << "Distance\n";
    cout << "In Miles: " << d1.distance.miles << endl;
    cout << "In meters: " << d1.distance.meters << endl;
    return 0;
}