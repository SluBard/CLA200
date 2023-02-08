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

    cout << "WORD COUNT: " << words.size() << endl << endl;
    
    auto unique_words = get_unique_words(words);

    cout << unique_words.size() << " UNIQUE WORDS: ";
    for (auto s : unique_words) {
        cout << s << ' ';
    }
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
    for (auto s : unique_words) {
        int c = words.count(s);
        cout << s << '=' << c << ' ';
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
    cout << endl << endl;
    return words;
}

set<string> get_unique_words(const multiset<string>& words) {
    set<string> unique_words;
    
    for (string word : words) {
        //auto search = unique_words.find(word);
        //if (search == unique_words.end()) {
            unique_words.insert(word);   // not found - add word with count of 1
        //}
    }
    return unique_words;
}
