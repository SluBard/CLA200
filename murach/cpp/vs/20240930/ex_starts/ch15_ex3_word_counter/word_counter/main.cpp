#include <iostream>
#include <fstream>
#include <string>
#include <set>
//#include <vector>
#include <map>

using namespace std;

multiset<string> display_and_load_words(string filename);
map<string, int> get_word_count(const multiset<string>& words);

int main() {
    cout << "The Word Counter program\n\n";

    string filename = "dickens.txt";
    auto words = display_and_load_words(filename);

    cout << "WORD COUNT: " << words.size() << endl << endl;
    /*
    for (string word : words) {
        cout << word << ' ';
    }
    cout << endl << endl;
    */
    auto word_count = get_word_count(words);

    cout << word_count.size() << " UNIQUE WORDS: ";
    for (auto pair : word_count) {
        cout << pair.first << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for (auto pair : word_count) {
        cout << pair.first << '=' << pair.second << ' ';
    }
    cout << endl << endl;
}

multiset<string> display_and_load_words(string filename) {
    multiset<string> words;
    ifstream infile(filename);

    if (infile) {
        string word;
        cout << "FILE TEXT: ";
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
    }
    cout << endl << endl;
    return words;
}

map<string, int> get_word_count(const multiset<string>& words) {
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
