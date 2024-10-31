#include <iostream>
#include <map>
#include <string>

using namespace std;

char get_choice() {
	char choice;
	cout << "Continue (y/n)?: ";
	cin >> choice;
	cout << endl;
	return choice;
}

void display_codes(const map<string, string>& countries) {
	cout << "Country codes: ";
	// display codes
	for (auto code : countries) {
		cout << code.first << " ";
	}
	cout << endl << endl;
}

void display_country(const map<string, string>& countries) {
	string code;
	cout << "Enter a country code: ";
	cin >> code;
	string upper_code = "";
	for (char c : code) {
		upper_code += toupper(c);
	}

	// get iterator for map element with code
	auto p = countries.find(upper_code);

	// if the code isn't found, display a message
	if (p == countries.end()) {
		cout << "Country code not found.\n\n";
	}
	
	// if the code is found, display the country name
	else {
		cout << "You selected " << p->second << endl << endl;
	}
}

int main()
{
	map<string, string> countries{ {"CA", "Canada"}, {"US", "United States"}, {"MX", "Mexico"} };

	cout << "The Country Codes Program\n\n";

	// display the country codes
	display_codes(countries);
	// while the user indicates they want to continue, display a country
	do {
		display_country(countries);
	} while (tolower(get_choice()) == 'y');
}

