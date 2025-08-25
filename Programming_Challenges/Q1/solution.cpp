#include <iostream>
using namespace std;

struct MovieData
{
    string Title;
    string Director;
    int ReleasedYear;
    string RunningTime;
    long double ProductionCost;
    long double FirstYearRevenue;
};

void inputData(MovieData &m)
{
    cout << "Enter Title of the Movie: " << endl;
    cin >> m.Title;
    cout << "Enter Director of the Movie: " << endl;
    cin >> m.Director;
    cout << "Enter Released Year of the Movie: " << endl;
    cin >> m.ReleasedYear;
    cout << "Enter Running time of the movie: " << endl;
    cin >> m.RunningTime;
    cout << "Enter Production Cost for the Movie: " << endl;
    cin >> m.ProductionCost;
    cout << "Enter First Year Revenue for the Movie: " << endl;
    cin >> m.FirstYearRevenue;
}

void showOutput(MovieData &m)
{
    cout << "--------------" << endl;
    cout << "Title: " << m.Title << endl;
    cout << "Director: " << m.Director << endl;
    cout << "Released Year: " << m.ReleasedYear << endl;
    cout << "Running Time (in minutes): " << m.RunningTime << endl;
    cout << "Production Cost: " << m.ProductionCost << endl;
    cout << "First Year Revenue: " << m.FirstYearRevenue << endl;
    cout << "--------------" << endl;
}

int main()
{
    MovieData m1, m2;
    inputData(m1);
    inputData(m2);
    showOutput(m1);
    showOutput(m2);
    return 0;
}