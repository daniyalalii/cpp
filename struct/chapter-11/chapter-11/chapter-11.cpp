#include <iostream>
#include <string>
using namespace std;

//struct savingAccounts {
//	string AccountNumber;
//	double AccountBalance;
//	double InterestRate;
//	double AverageMonthlyBalance;
//};

struct MovieDetails {
	string MovieName;
	string DirectorName;
	string ProducerName;
	int ReleaseYear;
};

int main()

{
	// 11.1 - 11.3
	
	// Activity 1 + 2
	//savingAccounts acc1 = { "124-234", 2940.43, 9.4, 50000.23 };
	//cout << "Account Number: " << acc1.AccountNumber << endl;
	//cout << "Account Balance: " << acc1.AccountBalance << endl;
	//cout << "Interest Rate: " << acc1.InterestRate <<endl;
	//cout << "Average Monthly Balance: " << acc1.AverageMonthlyBalance << endl;
	// --------------------

	// Activity 3
	// define the structure variable here.
	MovieDetails m1;

	cout << "Enter the following data about your\n";

	cout << "favorite movie.\n";
	cout << "name of the movie: \n";
	// Write a statement here that lets the user enter the
	// name of a favorite movie. Store the name in the
	// structure variable.
	getline(cin, m1.MovieName);
	cout << "Director: ";
	// Write a statement here that lets the user enter the
	// name of the movie's director. Store the name in the
	// structure variable.
	getline(cin, m1.DirectorName);
	cout << "Producer: ";
	// Write a statement here that lets the user enter the
	// name of the movie's producer. Store the name in the
	// structure variable.
	getline(cin, m1.ProducerName);
	cout << "Year of release (integer Only): ";
	// Write a statement here that lets the user enter the
	// year the movie was released. Store the year in the
	// structure variable.
	cin >> m1.ReleaseYear;
	cout << "Here is data on your favorite movie:\n";
	// Write statements here that display the data.
	// that just entered into the structure variable.
	cout << "\n--------------" << endl;
	cout << "Movie Name: " << m1.MovieName << endl;
	cout << "Director Name: " << m1.DirectorName << endl;
	cout << "Producer Name: " << m1.ProducerName << endl;
	cout << "Release Year: " << m1.ReleaseYear << endl;
	cout << "--------------" << endl;


	return 0;
}

