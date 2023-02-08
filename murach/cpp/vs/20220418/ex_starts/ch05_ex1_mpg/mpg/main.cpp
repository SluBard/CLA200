#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <fstream>

using namespace std;

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";

	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {

		// get miles driven
		double miles = 0;
		while (true) {
			cout << "Enter miles driven:        ";
			cin >> miles;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			// check for a valid number
			if (cin.fail()) {
				cout << "That's not a valid number. Please try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			// check the range of the number
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
			// check for a valid number
			if (cin.fail()) {
				cout << "That's not a valid number. Please try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			// check the range of the number
			if (gallons <= 0) {
				cout << "Gallons used must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// calculate miles per gallon
		double mpg = miles / gallons;
		mpg = round(mpg * 100) / 100;
		cout << "Miles per gallon:          " << mpg << endl << endl;

		// write to file
		ofstream outfile;
		outfile.open("trips.txt", ios::app);
		outfile << fixed << setprecision(1);
		outfile << miles << '\t' << gallons << endl;
		outfile.close();

		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	}

	cout << "Bye!\n\n";
}