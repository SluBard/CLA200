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

		string line;
		stringstream ss;
		string name;
		double hourly_wage = 0.0;
		double hours = 0.0;
		double wages = 0.0;
		int lines_not_processed = 0;

		cout << fixed << setprecision(2) << showpoint;
		cout << left << setw(15) << "Name" << right << setw(12) << "Hourly wage" << setw(12) << "Hours" << setw(12) << "Total" << endl;
		cout << left << setw(15) << "---------------" << right << setw(12) << " -----------" << setw(12) << " -----------" << setw(12) << " -----------" << endl;
		
		while (getline(infile, line)) {

			ss.str(line);
			ss.clear();

			if (ss >> name >> hourly_wage >> hours) {
				wages = hourly_wage * hours;
				cout << left << setw(15) << name << right << setw(12) << hourly_wage << setw(12) << hours << setw(12) << wages << endl;
			}
			else {
				++lines_not_processed;
			}
		}

		infile.close();

		cout << endl;
		cout << lines_not_processed << " records not processed.\n\n";
	}
}
