#include <iostream>
#include <string>
#include "validation.h"

using namespace std;
using namespace validation;

int main()
{
    cout << "Create Account\n\n";

    // get full name and parse first name
    string full_name;
    string first_name;
    bool valid_name = false;
    while (!valid_name) {
        cout << "Enter full name: ";
        getline(cin, full_name);

        // strip whitespace from front
        int i = full_name.find_first_not_of(" \n\t");
        if (i > -1) {
            full_name = full_name.substr(i);
        }

        // get first name
        int space_index = full_name.find(' ');
        if (space_index == -1) {
            cout << "You must enter your full name. Please try again.\n";
        }
        else {
            first_name = full_name.substr(0, space_index);
            valid_name = true;
        }
    }
    cout << endl;

    // get the password
    string password;
    bool valid_password = false;
    while (!valid_password) {

        // set valid flag
        valid_password = true;

		// get password
        cout << "Enter password: ";
        getline(cin, password);

		valid_password = is_valid_password(password);

        // display message if password is not valid
        if (!valid_password) {
            cout << "Please try again.\n";
        }
    }
    cout << endl;

	// get the email address
	string email;
	bool valid_email = false;
	while (!valid_email) {
		// set valid flag
		valid_email = true;

		// get email
		cout << "Enter email: ";
		getline(cin, email);

        valid_email = is_valid_email(email);

		// display message if email is not valid
		if (!valid_email) {
			cout << "Please try again.\n";
		}
	}
	cout << endl;

    // make sure first name uses initial cap
    char letter = first_name[0];
    first_name[0] = toupper(letter);
    for (int i = 1; i < first_name.length(); ++i) {
        letter = first_name[i];
        first_name[i] = tolower(letter);
    }

    // display welcome message
    cout << "Hi " << first_name << ",\n"
        << "Thanks for creating an account!\n\n";
}
