#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>


using namespace std;

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";

	double miles;
	double gallons;
	double mpg;
	double total_miles;
	double total_gallons;
	double avg_mpg;

	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {
		// read file
		ifstream infile;
		infile.open("trips.txt");
		if (infile) {
			total_miles = 0;
			total_gallons = 0;
			cout << fixed << setprecision(2) << setw(8) << "Miles" << setw(12) << "Gallons" << setw(12) << "MPG" << endl;

			while (infile >> miles >> gallons) {
				total_miles += miles;
				total_gallons += gallons;
				mpg = round(miles / gallons * 10) / 10;
				cout << setw(8) << miles << setw(12) << gallons << setw(12) << round(miles / gallons * 100) / 100 << endl;
			}
			infile.close();
			avg_mpg = total_miles / total_gallons;
			cout << fixed << setprecision(2) << showpoint << endl;
			cout << left << setw(15) << "Total Miles:" << right << setw(10) << total_miles << endl;
			cout << left << setw(15) << "Total Gallons:" << right << setw(10) << total_gallons << endl;
			cout << left << setw(15) << "Average MPG:" << right << setw(10) << avg_mpg << endl;
			cout << endl;
		}
		// get miles driven
		double miles = 0;
		while (true) {
			cout << "Enter miles driven:        ";
			cin >> miles;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (miles <= 0) {
				cout << "Miles driven must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// get gallons of gas used
		double gallons = 0;
		while (true) {
			cout << "Enter gallons of gas used: ";
			cin >> gallons;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (gallons <= 0) {
				cout << "Gallons used must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// calculate and display miles per gallon
		double mpg;
		mpg = miles / gallons;
		mpg = round(mpg * 100) / 100;
		cout << "Miles per gallon:          " << mpg << endl << endl;

		// write entry to file
		ofstream outfile;
		outfile.open("trips.txt", ios::app);
		outfile << fixed << setprecision(1);
		outfile << miles << '\t' << gallons << '\n';
		outfile.close();

		infile.open("trips.txt");
		if (infile) {
			total_miles = 0;
			total_gallons = 0;
			cout << fixed << setprecision(2) << setw(8) << "Miles" << setw(12) << "Gallons" << setw(12) << "MPG" << endl;

			while (infile >> miles >> gallons) {
				total_miles += miles;
				total_gallons += gallons;
				mpg = round(miles / gallons * 10) / 10;
				cout << setw(8) << miles << setw(12) << gallons << setw(12) << round(miles / gallons * 100) / 100 << endl;
			}
			infile.close();
			avg_mpg = total_miles / total_gallons;
			cout << fixed << setprecision(2) << showpoint << endl;
			cout << left << setw(15) << "Total Miles:" << right << setw(10) << total_miles << endl;
			cout << left << setw(15) << "Total Gallons:" << right << setw(10) << total_gallons << endl;
			cout << left << setw(15) << "Average MPG:" << right << setw(10) << avg_mpg << endl;
			cout << endl;
		}

		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
	}

	cout << "Bye!\n\n";
}