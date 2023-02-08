#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

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
        else if (score > -1) {     // valid score – add to vector
            scores.push_back(score);
        }
    }

    if (scores.empty()) {                 // vector is empty
        cout << "\nNo scores entered\n.";
    }
    else {                                 // vector contains scores
        // calculate total of all scores
        /*
        int total = 0;
        for (int score : scores) {
            total += score;
        }
        */
        int total = accumulate(scores.begin(), scores.end(), 0);

        // Sort in descending order
        cout << "\n";
        sort(scores.begin(), scores.end(), [](auto a, auto b) {return a > b; });
        for_each(scores.begin(), scores.end(), [](auto a) {cout << a << " "; });
        cout << "\n";
        cout << "Highest score: " << *max_element(scores.begin(), scores.end()) << "\n";
        cout << "Lowest score: " << *min_element(scores.begin(), scores.end()) << "\n";
        cout << "This student has " << count_if(scores.begin(), scores.end(), [](auto a) {return a == 100; }) << " perfect score(s)!\n";

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