#include <iostream>
using namespace std;

class car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    car(int ym, string mk)
    {
        yearModel = ym;
        make = mk;
        speed = 0;
    }
    void accessor()
    {
        cout << "Model: " << yearModel << endl;
        cout << "Make: " << make << endl;
        cout << "Current Speed: " << speed << endl;
    }
    void accelerate()
    {
        speed += 5;
    }
    void brake()
    {
        speed -= 5;
    }
};

int main()
{
    car c1(2025, "SUPRA");
    c1.accessor();
    c1.accelerate();
    c1.accessor();
    c1.accelerate();
    c1.accessor();
    c1.accelerate();
    c1.accessor();
    c1.accelerate();
    c1.accessor();
    c1.accelerate();
    c1.accessor();
    c1.brake();
    c1.accessor();
    c1.brake();
    c1.accessor();
    c1.brake();
    c1.accessor();
    c1.brake();
    c1.accessor();
    c1.brake();
    c1.accessor();

    return 0;
}