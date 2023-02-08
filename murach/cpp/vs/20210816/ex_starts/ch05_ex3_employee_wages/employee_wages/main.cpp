#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("wages.txt");
	if (infile) {
		string name;
		double wage;
		double hours;
		double total;
		string line; // buffer
		int lines_read = 0;
		int lines_processed = 0;
		stringstream ss;
		int col1 = 15;
		int col2 = 12;

		//table header
		cout << left << setw(col1) << "Name" << right << setw(col2) << "Hourly Wage" << setw(col2) << "Hours" << setw(col2) << "Total" << endl;
		cout << left << setw(col1) << "---------------" << right << setw(col2) << "-----------" << setw(col2) << "-----------" << setw(col2) << "-----------" << endl;

		while (getline(infile, line)) {
			lines_read++;
			ss.str(line);
			ss.clear();
			if (ss >> name >> wage >> hours) {
				lines_processed++;
				cout << fixed << setprecision(2);
				cout << left << setw(col1) << name;
				cout << right << setw(col2) << wage;
				cout << right << setw(col2) << hours;
				cout << right << setw(col2) << wage * hours << endl;
			}
		}
		infile.close();
		cout << endl << lines_read - lines_processed << " lines not processed.\n";
	}
}

