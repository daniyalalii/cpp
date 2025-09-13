#include <iostream>
using namespace std;

class ParkedCar
{
private:
    string carMake;
    int model;
    string color;
    string licenseNo;
    int minutesParked;

public:
    ParkedCar(string make = "", int mod = 0, string col = "", string lis = "", int minParked = 0)
    {
        carMake = make;
        model = mod;
        color = col;
        licenseNo = lis;
        minutesParked = minParked;
    }
    void getDetails()
    {
        cout << "-------------------------------------------" << endl;
        cout << "Car make: " << carMake << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "License Number: " << licenseNo << endl;
        cout << "Parked for " << minutesParked << " minutes" << endl;
    }
    int getMinutes()
    {
        return minutesParked;
    }
};

class ParkingMeter
{
private:
    int purchasedMinutes;

public:
    ParkingMeter(int minutes = 0)
    {
        purchasedMinutes = minutes;
    }
    int getPurchasedMinutes()
    {
        return purchasedMinutes;
    }
};

class ParkingTicket
{
public:
    void getReport(ParkedCar &c, ParkingMeter &m)
    {
        c.getDetails();
        int illegalMinutes = c.getMinutes() - m.getPurchasedMinutes();
        if (illegalMinutes > 0)
        {
            int hours = (illegalMinutes + 59) / 60;
            int fine = 25 + (hours > 1 ? (hours - 1) * 10 : 0);
            cout << "Fine: $" << fine << endl;
        }
        else
        {
            cout << "No violation. No ticket issued." << endl;
        }
    }
};

class PoliceOfficer
{
private:
    string name;
    string badgeNumber;

public:
    PoliceOfficer(string officerName = "", string badgeNum = "")
    {
        name = officerName;
        badgeNumber = badgeNum;
    }

    void examineCar(ParkedCar &car, ParkingMeter &meter)
    {
        int illegalMinutes = car.getMinutes() - meter.getPurchasedMinutes();
        if (illegalMinutes > 0)
        {
            ParkingTicket ticket;
            cout << "Ticket issued by Officer: " << name << ", Badge: " << badgeNumber << endl;
            ticket.getReport(car, meter);
        }
        else
        {
            cout << "Checked by Officer: " << name << ", Badge: " << badgeNumber << endl;
            cout << "No violation. No ticket issued." << endl;
        }
    }
};

int main()
{
    ParkedCar car("Toyota", 2020, "Red", "ABC123", 100);
    ParkingMeter meter(60);
    PoliceOfficer officer("Black Adam", "24JbP720");
    officer.examineCar(car, meter);
}