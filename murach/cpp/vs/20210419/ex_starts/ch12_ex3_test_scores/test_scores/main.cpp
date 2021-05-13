#include <iostream>

using namespace std;

int calculate_total(int scores[], int score_count);

int main() {
    //const int capacity = 50;
    //int scores[capacity] { 0 };  // set each element in array to 0
    const int maxstudents = 20;
    const int maxscores = 3;
    int scores[maxstudents][maxscores] = { 0 };

    cout << "The Test Scores program\n\n";

    cout << "Enter test scores (" << maxscores << " per student, " << maxstudents << " max students).\n"
         << "Make sure each score is between 0 and 100.\n"
         << "To end the program, enter -1.\n";

    // initialize counter and score variables
    int score_count = 0, score = 0,student_count=0;

    // prevent out of bounds access by making sure
    // score count is less than capacity
    while (score != -1 && student_count < maxstudents) {
        cout << "\nStudent " << student_count+1 << "\n";
        score_count = 0;
        score = 0;
        while (score != -1 && score_count < maxscores) {
            cout << "Enter score: ";
            cin >> score;

            if (cin.fail()) {
                cin.clear();             // clear bad input flag
                cin.ignore(1000, '\n');  // discard input up to end of line
                cout << "Invalid number. Try again.\n";
            } else if (score > 100) {
                cout << "Score must be from 0 to 100. Try again.\n";
            } else if (score < -1) {
                cout << "Score can't be a negative number. Try again.\n";
            } else if (score > -1) {
                scores[student_count][score_count] = score;   // store score in array
                ++score_count;  // increment score count
            }
        }
        ++student_count; // new
    }
    cout << endl;

    if (student_count == 0) {
        cout << "No scores entered.\n\n";
    }
    else {
        // calculate total and average scores
        for (int student = 0; student < student_count-1; student++) {
            cout << "Student " << student+1 << ": ";
            for (int i = 0; i < maxscores; i++){
                cout << scores[student][i] << " ";
            }
            double total = calculate_total(scores[student], maxscores);
            double average = total / maxscores;
            average = round(average * 10) / 10;
            cout << "\tAvg score: " << average << "\n";

            // display the score count, score total, and average score
            //cout << "Score count:   " << score_count << endl
            //    << "Score total:   " << total << endl
            //    << "Average score: " << average << endl;
        }
    }

    return 0;
}

int calculate_total(int scores[], int score_count) {
    int total = 0.0;
    for (int i = 0; i < score_count; ++i) {
        total += scores[i];
    }
    return total;
}