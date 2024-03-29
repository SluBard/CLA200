#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> load_words(string filename);
map<string, int> get_word_count(const vector<string>& words);

void display(pair<string, int>);
bool over_1(pair<string, int>);

int main() {
	cout << "The Word Counter program\n\n";

	string filename = "dickens.txt";
	auto words = load_words(filename);

	cout << words.size() << " WORDS: ";
	for (string word : words) {
		cout << word << ' ';
	}
	cout << endl << endl;

	auto word_count = get_word_count(words);

	cout << word_count.size() << " UNIQUE WORDS: ";
	for (auto pair : word_count) {
		cout << pair.first << ' ';
	}
	cout << endl << endl;

	cout << "COUNT PER WORD: ";
	for_each(word_count.begin(),word_count.end(), display);
	//for (auto pair : word_count) {
	//	cout << pair.first << '=' << pair.second << ' ';
	//}
	cout << endl << endl;

	cout << count_if(word_count.begin(), word_count.end(), over_1) << " DUPLICATE WORDS\n";
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
	}
	return words;
}

map<string, int> get_word_count(const vector<string>& words) {
	map<string, int> word_count{};

	for (string word : words) {
		auto search = word_count.find(word);
		if (search == word_count.end()) {
			word_count[word] = 1;   // not found - add word with count of 1
		}
		else {
			word_count[word] += 1;  // found - increment count for word
		}
	}
	return word_count;
}
void display( pair<string, int> p) {
	cout << p.first << "=" << p.second << " ";
}
bool over_1( pair<string, int> p) {
	return(p.second > 1);
}