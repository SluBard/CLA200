#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";

	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {

		double miles = 0;
		double gallons = 0;
		double total_miles = 0;
		double total_gallons = 0;

		//Read from file
		string filename = "trips.txt";
		ifstream input_file;

		cout << setw(8) << "Miles" << setw(12) << "Gallons" << setw(12) << "MPG\n";
		input_file.open(filename);
		if (input_file) {     // if file opened successfully...
			cout << fixed << setprecision(1);
			while (input_file >> miles >> gallons) {
				total_miles += miles;
				total_gallons += gallons;
				cout << setw(8) << miles << setw(12) << gallons <<setw(12) << round(miles/gallons * 100) / 100 << '\n';
			}
			input_file.close();
			cout << "\n";
			cout << fixed << setprecision(2);
			cout << left << setw(14) << "Total Miles:" << right << setw(11) << total_miles << "\n";
			cout << left << setw(14) << "Total Gallons:" << right << setw(11) << total_gallons << "\n";
			cout << left << setw(14) << "Average MPG:" << right << setw(11) << total_miles/total_gallons << "\n\n";
		}
		else {
			cout << "Unable to open file.\n";
		}

		// get miles driven

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

		total_miles = 0;
		total_gallons = 0;
		cout << setw(8) << "Miles" << setw(12) << "Gallons" << setw(12) << "MPG\n";
		input_file.open(filename);
		if (input_file) {     // if file opened successfully...
			cout << fixed << setprecision(1);
			while (input_file >> miles >> gallons) {
				total_miles += miles;
				total_gallons += gallons;
				cout << setw(8) << miles << setw(12) << gallons << setw(12) << round(miles / gallons * 100) / 100 << '\n';
			}
			input_file.close();
			cout << "\n";
			cout << fixed << setprecision(2);
			cout << left << setw(14) << "Total Miles:" << right << setw(11) << total_miles << "\n";
			cout << left << setw(14) << "Total Gallons:" << right << setw(11) << total_gallons << "\n";
			cout << left << setw(14) << "Average MPG:" << right << setw(11) << total_miles / total_gallons << "\n\n";
		}
		else {
			cout << "Unable to open file.\n";
		}

		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
        cout << endl;
	}

	cout << "Bye!\n\n";
}