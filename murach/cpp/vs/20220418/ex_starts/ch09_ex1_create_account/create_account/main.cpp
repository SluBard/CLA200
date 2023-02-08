#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Account {
	string first="";
	string last="";
	string passwd="";
	string email="";
	bool equals(const Account& a);
};

bool Account::equals(const Account& a) {
	return (email == a.email);
}

const string accounts_file = "accounts.txt";

void display_accounts(const vector<Account> &accounts) {
	int col_width = 10;
	cout << left
		<< setw(col_width * 3) << "Name"
		<< setw(col_width * 4) << "Email" << endl;
	for( Account a: accounts){
		
		cout << setw(col_width * 3) << a.first + ' ' + a.last << setw(col_width * 4) << a.email << endl;
	}
	cout << endl;
}

vector<Account> read_accounts_from_file() {
	vector<Account> accounts;
	ifstream input_file(accounts_file);
	if (input_file) {
		Account account;
		while (input_file >> account.first >> account.last >> account.passwd >> account.email) {
			accounts.push_back(account);
		}
		input_file.close();
	}
	return accounts;
}

void write_accounts_to_file(const vector<Account> &accounts) {
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
		bool duplicate = false;
		for (Account account : accounts) {
			if (account.equals(a) == true) {
				duplicate = true;
				break;
			}
		}
		if (duplicate == true) {
			cout << a.email << " already exists - account not added." << endl << endl;
		}
		else {
			accounts.push_back(a);
			write_accounts_to_file(accounts);
			cout << endl << a.email << " was added for " << a.first + ' ' + a.last << endl << endl;
		}
		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}
}
