#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    cout << "The Future Value Calculator\n\n";

    vector<double>monthly;
    vector<double>rate;
    vector<double>term;
    vector<double>fv;

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double monthly_investment;
        cout << "Enter monthly investment:   ";
        cin >> monthly_investment;

        double yearly_rate;
        cout << "Enter yearly interest rate: ";
        cin >> yearly_rate;

        int years;
        cout << "Enter number of years:      ";
        cin >> years;

        // convert yearly values to monthly values
        double monthly_rate = yearly_rate / 12 / 100;
        int months = years * 12;

        // calculate future value
        double future_value = 0;
        for (int i = 1; i <= months; i++) {
            future_value = (future_value + monthly_investment) *
                (1 + monthly_rate);
        }

		// round to 2 decimal places and display
		future_value = round(future_value * 100) / 100;
		cout << "Future value:               " << fixed << setprecision(2) << future_value << "\n\n";

        monthly.push_back(monthly_investment);
        rate.push_back(yearly_rate);
        term.push_back(years);
        fv.push_back(future_value);

        // see if the user wants to continue
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    }

    cout << setw(10) << "Monthly" << setw(8) << "Yearly" << endl;
    cout << setw(10) << "investment" << setw(8) << "rate" << setw(7) << "Years" << setw(14) << "Future Value" << endl;
    for (int i = 0; i < fv.size(); i++) {
        cout << fixed << setprecision(2);
        cout << setw(10)<<monthly.at(i);
        cout << setw(8) << rate.at(i);
        cout << setw(7) << setprecision(0) << term.at(i) << setprecision(2);
        cout << setw(14) << fv.at(i) << "\n";
    }

    cout << "Bye! ";
}