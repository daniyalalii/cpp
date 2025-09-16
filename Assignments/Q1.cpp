#include <iostream>
using namespace std;

struct Weather
{
    int days;
    double temperature;
    double humidity;
    double rainfall;
};

void getData(Weather w[])
{
    for (int i = 0; i < 7; i++)
    {
        w[i].days = i + 1;
        cout << string(47, '-') << endl;
        cout << "Enter data for day: " << w[i].days << endl;
        cout << "Enter the temperature: " << endl;
        cin >> w[i].temperature;
        do
        {
            cout << "Enter the humidity (in %): " << endl;
            cin >> w[i].humidity;
        } while (w[i].humidity < 0);
        do
        {
            cout << "Enter the rainfall (in mm)" << endl;
            cin >> w[i].rainfall;
        } while (w[i].rainfall < 0);
    }
}

void avgTemperature(Weather w[])
{
    double totalTemp = 0.0;
    int Day = w[0].days;
    double maxTemp = w[0].temperature;
    for (int i = 0; i < 7; i++)
    {
        totalTemp += w[i].temperature;
        if (w[i].temperature > maxTemp)
        {
            maxTemp = w[i].temperature;
            Day = w[i].days;
        }
    }
    double avgTemp = totalTemp / 7.0;
    cout << string(47, '-') << endl;
    cout << "Average Temperature during this week is: " << avgTemp << " °C" << endl;
    cout << "Maximum Temperature was: " << maxTemp << " °C on Day: " << Day << endl;
    cout << string(47, '-') << endl;
}
void avgHumidity(Weather w[])
{
    double totalHumidity = 0.0;
    for (int i = 0; i < 7; i++)
    {
        totalHumidity += w[i].humidity;
    }
    double avgHum = totalHumidity / 7.0;
    cout << string(47, '-') << endl;
    cout << "Average Humidity for first seven days: " << avgHum << endl;
    cout << string(47, '-') << endl;
}

void totalRainfall(Weather w[])
{
    double totalRainfall = 0.0;
    int Day = w[0].days;
    double maxRainfall = w[0].rainfall;
    for (int i = 0; i < 7; i++)
    {
        totalRainfall += w[i].rainfall;
        if (w[i].rainfall > maxRainfall)
        {
            maxRainfall = w[i].rainfall;
            Day = w[i].days;
        }
    }
    cout << string(47, '-') << endl;
    cout << "Total RainFall for this week is: " << totalRainfall << "mm" << endl;
    cout << "Maximum rainfall was: " << maxRainfall << "mm during Day: " << Day << endl;
    cout << string(47, '-') << endl;
}
void printRecord(Weather w[])
{
    cout << left << "Day"
          << "          Temperature"
          << "            Humidity"
          << "            Rainfall" << endl;
    cout << string(67, '-') << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << left << (i + 1)
             << "               " << w[i].temperature
             << "                       "<< w[i].humidity
             << "                     " << w[i].rainfall << endl;
    }
    cout << string(67, '-') << endl;
}

int main()
{
    const int weekdays = 7;
    int input;
    Weather week1[weekdays];
    // getting input for week1 data
    getData(week1);

    do
    {
        cout << "1- Print the records for 7 days" << endl;
        cout << "2- Print Average Temperature " << endl;
        cout << "3- Print Average Humidity" << endl;
        cout << "4- Print Total Rainfall" << endl;
        cout << "0- End the Program" << endl;
        cin >> input;
        switch (input)
        {
        case 1:
        {
            printRecord(week1);
            break;
        }
        case 2:
        {
            avgTemperature(week1);
            break;
        }
        case 3:
        {
            avgHumidity(week1);
            break;
        }
        case 4:
            totalRainfall(week1);
            break;
        case 0:
        {
            cout << "Thank You for using the program" << endl;
            break;
        }
        default:
        {
            cout << "Enter correct input" << endl;
            break;
        }
        }
    } while (input != 0);

    return 0;
}