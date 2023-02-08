#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main() {
    cout << "Let's Play Word Jumble!\n"
        << "\n"
        << "Enter 'hint' for a hint.\n"
        << "Enter 'exit' to exit.\n\n";

    // define a vector of possible words
    const int rows = 3;
    const int cols = 9;
    //vector<string> words { "guitar", "violin", "tapestry" };
    char words[rows][cols]={ "guitar", "violin", "tapestry" };

    // get random word from vector
    srand(time(nullptr));
    //int index = rand() % words.size();
    int index = rand() % rows;
    //string word = words[index];
    //char *word = words[index];
    char word[cols]="";
    //strncpy(word, words[index],cols);
    strncpy(word, words[index], strlen(words[index])+1);
    cout << strlen(words[index]) << "\n";

    // jumble the word
    //string jumbled_word = word;
    char jumbled_word[cols] = "";
    strncpy(jumbled_word, word, strlen(word)+1);
    //auto length = word.size();
    auto length = strlen(word);
    for (int index1 = 0; index1 < length; ++index1) {
        int index2 = rand() % length;
        char temp = jumbled_word[index1];
        jumbled_word[index1] = jumbled_word[index2];
        jumbled_word[index2] = temp;
    }

    // display the jumbled word in upper case
    cout << "The jumble is...";
    for (char c : jumbled_word) {
        cout << (char)toupper(c);
    }
    cout << "\n\n";

    // loop until the user guesses the jumble or enters 'exit'
    int hint_count = 1;
    //string guess = "";
    char guess[cols] = "";
    while (guess != "exit") {
        cout << "Your guess: ";
        cin >> guess;
        cin.ignore(1000, '\n');

        //if (guess == word) {
        if (strcmp(guess,word)==0) {
            cout << "Congratulations! You guessed it.\n\n";
            break;
        }
        //else if (guess == "hint") {
        else if (strcmp(guess,"hint")==0) {
            cout << "Hint: ";
            //for (int i = 0; i < word.length(); ++i) {
            for (int i = 0; i < strlen(word); ++i) {
                if (i < hint_count) {
                    cout << static_cast<char>(toupper(word[i])) << ' ';
                }
                else {
                    cout << '_' << ' ';
                }
            }
            cout << "\n\n";
            ++hint_count;
        }
        else if (guess == "exit") {
            cout << "Bye! Let's play again soon.\n\n";
        }
        else {
            cout << "Nope. Try again!\n\n";
        }
    }
}
