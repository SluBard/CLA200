#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

multiset<string> display_and_load_words(string filename);
set<string> get_unique_words(const multiset<string>& words);

int main() {
    cout << "The Word Counter program\n\n";

    string filename = "dickens.txt";
    auto words = display_and_load_words(filename);
/*
    cout << words.size() << " WORDS: ";
    for (string word : words) {
        cout << word << ' ';
    }
    cout << endl << endl;
*/
    cout << "\nWORD COUNT: " << words.size() << "\n\n";
    auto word_count = get_unique_words(words);

    cout << word_count.size() << " UNIQUE WORDS: ";
    for (auto word : word_count) {
        cout <<  word << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for (auto word : word_count) {
        cout << word << '=' << words.count(word) << ' ';
    }
    cout << endl << endl;
}

multiset<string> display_and_load_words(string filename) {
    multiset<string> words;
    ifstream infile(filename);

    if (infile) {
        string word;
        while (infile >> word) {
            cout << word << " ";
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
			//cout << new_word << ' ';
            words.insert(new_word);      // add word 
        }
        infile.close();
        cout << "\n";
    }
    return words;
}

set<string> get_unique_words(const multiset<string>& words) {
    set<string> unique_words{};

    for (string word : words) {
        auto search = unique_words.find(word);
        if (search == unique_words.end()) {
            unique_words.insert(word); 
        }
    }
    return unique_words;
}
