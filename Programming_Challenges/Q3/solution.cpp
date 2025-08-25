#include <iostream>
using namespace std;

const int TotalMonths = 12;

enum Months
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

struct WeatherData
{
    double TotalRainfall;
    double HighTemperature;
    double LowTemperature;
    double AvgTemperature;
};

void inputData(WeatherData d[])
{
    for (int i = January; i <= December; i++)
    {
        cout << "Enter data for month: " << i + 1 << endl;
        cout << "Enter total rainfall: " << endl;
        cin >> d[i].TotalRainfall;
        do
        {
            cout << "Enter Highest temperature: (-100 to +140) fahrenheit" << endl;
            cin >> d[i].HighTemperature;
        } while (d[i].HighTemperature > 140);
        do
        {
            cout << "Enter Lowest Temperature: " << endl;
            cin >> d[i].LowTemperature;
        } while (d[i].LowTemperature < -100);
        d[i].AvgTemperature = (d[i].HighTemperature + d[i].LowTemperature) / 2.0;
    }
}

void showData(WeatherData d[])
{
    for (int i = January; i <= December; i++)
    {
        cout << "------------" << endl;
        cout << "Month " << i + 1 << ": "
             << "Rainfall=" << d[i].TotalRainfall << " | "
             << "High=" << d[i].HighTemperature << " | "
             << "Low=" << d[i].LowTemperature << " | "
             << "Avg=" << d[i].AvgTemperature << endl;
    }
}

int main()
{
    WeatherData data[TotalMonths];
    inputData(data);
    showData(data);
    return 0;
}