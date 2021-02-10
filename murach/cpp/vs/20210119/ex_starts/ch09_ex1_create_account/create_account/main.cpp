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
	string password = "";
	string email = "";
	bool equals(Account& other) {
		return (email == other.email);
	}
};

vector<Account> read_accounts_from_file() {
	vector<Account> accounts;
	Account account;

	ifstream input_file(accounts_file);
	if (input_file) {

		while (input_file >> account.first >> account.last >> account.password >> account.email) {
			accounts.push_back(account);
		}
		input_file.close();
	}
	return accounts;
}


//void display_accounts(string first, string last, string password, string email) {
void display_accounts(const vector<Account>& accounts) {
	int col_width = 10;
	cout << left
		<< setw(col_width * 3) << "Name"
		<< setw(col_width * 4) << "Email" << endl;
	for (Account a : accounts) {
		cout << setw(col_width * 3) << a.first + ' ' + a.last
			<< setw(col_width * 4) << a.email << endl;
	}
}

void write_accounts_to_file(const vector<Account>& accounts) {
	ofstream output_file(accounts_file);
	if (output_file) {
		for (Account a : accounts)
			output_file << a.first << '\t'
			<< a.last << '\t'
			<< a.password << '\t'
			<< a.email << '\n';
		output_file.close();
	}
}
Account get_account() {
	Account account;
	cout << "First name: ";
	getline(cin, account.first);
	cout << "Last name: ";
	getline(cin, account.last);
	cout << "Password: ";
	getline(cin, account.password);
	cout << "Email: ";
	getline(cin, account.email);
	return account;
}

int main()
{
	cout << "Create Account List\n\n";

	vector<Account> accounts = read_accounts_from_file();

	display_accounts(accounts);

	char another = 'y';
	while (tolower(another) == 'y') {
		bool found = false;
		Account account = get_account();
		for (Account a : accounts) {
			if ( a.equals(account) ){
				found = true;
				break;
			}
		}
		if (!found) {
			accounts.push_back(account);
			write_accounts_to_file(accounts);

			cout << endl << account.email << " was added for "
				<< account.first + ' ' + account.last << endl << endl;
		}
		else {
			cout << "Account '" << account.email << "' exists - Not Added\n";
		}

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}

	display_accounts(accounts);
}
