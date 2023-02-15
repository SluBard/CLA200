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
    string email = "";
	bool equals(Account rhs) { 
		return email == rhs.email;
	}
};

const string accounts_file = "accounts.txt";

vector<Account> read_accounts_from_file() {
  vector<Account> accounts;
  Account account;

  ifstream input_file(accounts_file);
  if (input_file) {
    while (input_file >> account.first >> account.last >> account.passwd >> account.email) {
      accounts.push_back(account);
    }
    input_file.close();
  }
  return accounts;
}

void display_accounts( vector<Account> accounts) {
	int col_width = 10;
	cout << left << setw(col_width * 3) << "Name" << setw(col_width * 4) << "Email" << endl;

	for( Account account : accounts ) {
		cout << setw(col_width * 3) << account.first + ' ' + account.last
			<< setw(col_width * 4) << account.email << endl;
	}
	cout << endl;
}

void write_account_to_file(vector<Account> accounts) {
	ofstream output_file(accounts_file); //, ios::app);
	if (output_file) {
          for (Account account : accounts) {
            output_file << account.first << '\t' << account.last << '\t' << account.passwd << '\t' << account.email << '\n';
          }
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
	getline(cin, account.passwd);
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
        Account account = get_account();
        for (Account acc : accounts) {
          if (acc.equals(account)) {
            cout << account.email << " already exists - account not added.\n";
            break;
          }
          accounts.push_back(account);
          write_account_to_file(accounts);

          cout << endl
               << account.email << " was added for "
               << account.first + ' ' + account.last << endl
               << endl;
		}

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}

	display_accounts(accounts);
}
