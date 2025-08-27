#include <iostream>
#include <iomanip>
using namespace std;
// Write your function prototype here.
void convert(double *);
int main()
{
    double measurement;
    cout << "Enter a length in inches, and I will convert\n";
    cout << "it to centimeters: ";
    cin >> measurement;
    convert(&measurement);
    cout << fixed << setprecision(4);
    cout << "Value in centimeters: " << measurement << endl;
    return 0;
}
//
// Write the function convert here.
//
void convert(double *ptr){
    *ptr *= 1.54;
}