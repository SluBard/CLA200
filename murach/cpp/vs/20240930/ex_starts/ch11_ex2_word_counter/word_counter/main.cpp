#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct FileNotFound {
	string message;
	string filename;
};

vector<string> load_words(string filename);

int main() {
	cout << "The Word Counter program\n\n";

	string filename = "";
	cout << "Enter a file name: ";
	cin >> filename;

	vector<string> words;
	try {
		words = load_words(filename);

		cout << endl;
		cout << words.size() << " WORDS: ";
		for (string word : words) {
			cout << word << ' ';
		}
		cout << endl << endl;
	}
	catch (const FileNotFound& e) {
		cout << e.message << endl;
		cout << "You entered: " << e.filename << ".\n";
		cout << "Exiting program...";
	}
	catch (...) {
		throw;
	}
}

vector<string> load_words(string filename) {
	vector<string> words;
	ifstream infile(filename);

	if (infile) {
		string word;
		while (infile >> word) {

			string new_word = "";
			for (char c : word) {
				if (c == '.' || c == ',') {
					continue;               // remove punctuation
				}
				else if (isupper(c)) {
					new_word += tolower(c); // convert to lowercase
				}
				else {
					new_word += c;
				}
			}
			words.push_back(new_word);      // add word 
		}
		infile.close();
		return words;
	}
	else {
		FileNotFound e{ "File not found.", filename };
		throw e;
	}

}