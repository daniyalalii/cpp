#include <iostream>
using namespace std;

struct MovieData
{
    string Title;
    string Director;
    int ReleasedYear;
    string RunningTime;
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
}

void showOutput(MovieData &m)
{
    cout << "Title: " << m.Title << endl;
    cout << "Director: " << m.Director << endl;
    cout << "Released Year: " << m.ReleasedYear << endl;
    cout << "Running Time (in minutes): " << m.RunningTime << endl;
}

int main()
{
    MovieData m1, m2;
    inputData(m1);
    inputData(m2);
    cout << "-------------" << endl;
    showOutput(m1);
    showOutput(m2);
    cout << "-------------" << endl;
    return 0;
}