#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

multiset<string> display_and_load_words(string filename);
set<string> get_unique_words(const multiset<string>& words);

int main() {
    cout << "The Word Counter program\n\n";

    string filename = "dickens.txt";
    cout << "FILE TEXT: ";
    auto words = display_and_load_words(filename);

    cout << "\n\nWORD COUNT: " << words.size();
    cout << endl << endl;

    auto word_count = get_unique_words(words);

    cout << word_count.size() << " UNIQUE WORDS: ";
    for (auto word : word_count) {
        cout << word << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for (auto word : word_count) {
        cout << word << "=" << words.count(word) << " ";
    }
    cout << endl << endl;
}

multiset<string> display_and_load_words(string filename) {
    multiset<string> words;
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
            cout << word << ' ';
            words.insert(new_word);      // add word 
        }
        infile.close();
    }
    return words;
}

set<string> get_unique_words(const multiset<string>& words) {
    set<string> unique_words{};

    for (string word : words) {
        unique_words.insert(word);
    }
    return unique_words;
}
