#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool descending(int a, int b) {
    return a > b;
}
void display(int a) {
    cout << a << " ";
}
int main()
{
    cout << "The Test Scores program\n\n";

    cout << "Enter test scores from 0 to 100.\n"
        << "To end the program, enter -1.\n\n";

    vector<int> scores;
    int score = 0;
    while (score != -1) {
        cout << "Enter score: ";
        cin >> score;

        if (cin.fail()) {
            cin.clear();             // clear error bits
            cin.ignore(1000, '\n');  // discard input up to end of line
            cout << "Invalid number. Try again.\n";
        }
        else if (score > 100) {
            cout << "Score must be from 0 to 100. Try again.\n";
        }
        else if (score < -1) {
            cout << "Score can't be a negative number. Try again.\n";
        }
        else if (score > -1) {     // valid score � add to vector
            scores.push_back(score);
        }
    }

    if (scores.empty()) {                 // vector is empty
        cout << "\nNo scores entered\n.";
    }
    else {                                 // vector contains scores
        //new code
        cout << endl << endl;

        sort(scores.begin(), scores.end(), descending);
        for_each(scores.begin(), scores.end(), display);
        cout << endl;
        cout << "Highest Score: " << *max_element(scores.begin(), scores.end()) << endl;
        cout << "Lowest Score: " << *min_element(scores.begin(), scores.end()) << endl;
        cout << "This student has " << count(scores.begin(),scores.end(), 100) << " perfect score(s)!\n\n";
        // calculate total of all scores
        int total = 0;
        for (int score : scores) {
            total += score;
        }

        // get the count and calculate the average
        auto score_count = scores.size();
        double average = static_cast<double>(total) / score_count;
        average = round(average * 10) / 10;

        // display the score count, total, and average
        cout << '\n'  // blank line
            << "Score count:   " << score_count << endl
            << "Score total:   " << total << endl
            << "Average score: " << average << endl << endl;
    }
}
