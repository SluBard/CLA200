#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << "The Future Value Calculator\n\n";

    vector<double> monthly_inv;
    vector<double> yearly_rte;
    vector<int> yrs;
    vector<double> fv;
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
        monthly_inv.push_back(monthly_investment);
        yearly_rte.push_back(yearly_rate);
        yrs.push_back(years);
        fv.push_back(future_value);

		// round to 2 decimal places and display
		future_value = round(future_value * 100) / 100;
        cout << fixed << setprecision(2);
		cout << "Future value:               " << future_value << "\n\n";

        // see if the user wants to continue
        cout << "Continue? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << fixed << setprecision(2);
    cout << setw(10) << "Monthly" << setw(8) << "Yearly" << "\n";
    cout << setw(10) << "investment" << setw(8) << "rate" << setw(7) << "Years" << setw(14) << "Future Value" << "\n";
    for (int i = 0; i < fv.size(); ++i) {
        cout << setw(10) << round(monthly_inv[i] * 100) / 100;
        cout << setw(8) << round(yearly_rte[i] * 100) / 100;
        cout << setw(7) << yrs[i];
        cout << setw(14) << round(fv[i] * 100) / 100 << "\n";
    }
    cout << "Bye! ";
}