#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const string accounts_file = "accounts.txt";

struct Account {
	string first = "";
	string last = "";
	string passwd = "";
	string email = "";
};

vector<Account> read_accounts_from_file() {
	ifstream input_file(accounts_file);
	vector<Account> accounts;
	if (input_file) {
		while(true){
			Account a;
			if (input_file >> a.first >> a.last >> a.passwd >> a.email) {
				accounts.push_back(a);
			}
			else {
				break;
			}
		}
		input_file.close();
	}
	return accounts;
}

void display_accounts(const vector<Account> &accounts) {
	int col_width = 10;
	cout << left
		<< setw(col_width * 3) << "Name"
		<< setw(col_width * 4) << "Email" << endl;
	for( Account a : accounts){
		cout << setw(col_width * 3) << a.first + ' ' + a.last
			<< setw(col_width * 4) << a.email << endl;
	}
	cout << endl;
}
void write_account_to_file(const vector<Account> &accounts) {
	ofstream output_file(accounts_file);
	if (output_file) {
		for (Account a : accounts) {
			output_file << a.first << '\t'
				<< a.last << '\t'
				<< a.passwd << '\t'
				<< a.email << '\n';
		}
		output_file.close();
	}
}
Account get_account() {
	Account a;
	cout << "First name: ";
	getline(cin, a.first);
	cout << "Last name: ";
	getline(cin, a.last);
	cout << "Password: ";
	getline(cin, a.passwd);
	cout << "Email: ";
	getline(cin, a.email);
	return a;
}

int main()
{
    cout << "Create Account List\n\n";

	vector<Account> accounts = read_accounts_from_file();

	display_accounts(accounts);

	char another = 'y';
	while (tolower(another) == 'y') {
		Account a = get_account();
		accounts.push_back(a);
		write_account_to_file(accounts);
		
		cout << endl << a.email << " was added for "
			<< a.first + ' ' + a.last << endl << endl;

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}
	display_accounts(accounts);
}
