#include <iostream>
using namespace std;

class FuelGauge
{
private:
    int fuelsInGallons;

public:
    FuelGauge(int fuel = 0)
    {
        fuelsInGallons = fuel;
    }
    void setMileage(int input)
    {
        fuelsInGallons = input;
    }
    int getFuel()
    {
        return fuelsInGallons;
    }
    void GetFuelReport()
    {
        cout << "Current Fuel in car is: " << fuelsInGallons << " Gallon" << endl;
        cout << "----------------------------" << endl;
    }
    void incrementFuel()
    {
        if (fuelsInGallons > 15)
        {
            cout << "Cannot hold more gallon of fuel\nMaximum Gallons holded" << endl;
            cout << "----------------------------" << endl;
            return;
        }
        else
        {
            fuelsInGallons += 1;
            cout << "1 Gallon of fuel increase for car" << endl;
            cout << "----------------------------" << endl;
        }
    }
    void decrementFuel()
    {
        if (fuelsInGallons < 0)
        {
            cout << "Cannot remove more gallons\nMinimum Gallons amount reached" << endl;
            cout << "----------------------------" << endl;
            return;
        }
        else
        {
            fuelsInGallons -= 1;
            cout << "1 Gallon of fuel decreased for car" << endl;
            cout << "----------------------------" << endl;
        }
    }
};

class Odometer
{
private:
    int mileage;

public:
    Odometer(int m = 0) : mileage(m) {}
    void getMileage()
    {
        cout << "Current Mileage for car is: " << mileage << endl;
        cout << "----------------------------" << endl;
    }
    void incrementMileage()
    {
        if (mileage > 999999)
        {
            mileage = 0;
            cout << "Reseted the mileage" << endl;
            cout << "----------------------------" << endl;
        }
        else
        {
            mileage += 1;
            cout << "Mileage increase by 1" << endl;
            cout << "----------------------------" << endl;
        }
    }
    int Mileage()
    {
        return mileage;
    }
};

int main()
{
    FuelGauge carFuel;
    Odometer carMeter(1000);
    int input;
    cout << "Enter the amount of gallons for your car 1-15" << endl;
    cin >> input;
    carFuel.setMileage(input);

    carFuel.GetFuelReport();
    carMeter.incrementMileage();
    carMeter.getMileage();
    while (carFuel.getFuel() != 0)
    {
        carFuel.GetFuelReport();
        carMeter.getMileage();
        if (carMeter.Mileage() > 24)
        {
            carFuel.decrementFuel();
        }
        carMeter.incrementMileage();
    }
    return 0;
}