#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> load_words(string filename);

struct FileNotFound {
	string msg;
	string filename;
};

int main() {
	cout << "The Word Counter program\n\n";

	string filename = "";
	cout << "Enter a file name: ";
	cin >> filename;

	vector<string> words;
        try {
          words = load_words(filename);
        } 
		catch (const FileNotFound &e) {
          cout << e.msg;
          cout << "You entered: " << e.filename << ".\n";
          cout << "Exiting program...";
          return 0;
		}
		catch (...) {
          throw;
		}
	cout << endl;
	cout << words.size() << " WORDS: ";
	for (string word : words) {
		cout << word << ' ';
	}
	cout << endl << endl;
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
    } else {
        FileNotFound error;
		error.filename = filename;
        error.msg = "File not found.\n";
        throw error;
	}
	return words;
}