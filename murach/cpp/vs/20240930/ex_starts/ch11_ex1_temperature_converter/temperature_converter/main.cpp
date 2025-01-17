#include <iostream>
#include <cmath>

using namespace std;

// declare functions
void display_menu();
void convert_temp();
double to_celsius(double fahrenheit);
double to_fahrenheit(double celsius);

int main() {

	cout << "Convert Temperatures\n\n";

    display_menu();
    char again = 'y';
    while (again == 'y') {
        convert_temp();

        cout << "Convert another temperature? (y/n): ";
        cin >> again;
        cout << endl;
    }
    cout << "Bye!\n";
}

// define functions
void display_menu() {
    cout << "MENU\n"
        << "1. Fahrenheit to Celsius\n"
        << "2. Celsius to Fahrenheit\n\n";
}

void convert_temp() {
    int option;
    cout << "Enter a menu option: ";
    cin >> option;

    double f = 0.0;
    double c = 0.0;
    switch (option) {
    case 1:
        cout << "Enter degrees Fahrenheit: ";
        cin >> f;

        try {
            c = to_celsius(f);
            c = round(c * 10) / 10;

            cout << "Degrees Celsius: " << c << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl << endl;
        }
        break;
    case 2:
        cout << "Enter degrees Celsius: ";
        cin >> c;

        try {
            f = to_fahrenheit(c);
            f = round(f * 10) / 10;

            cout << "Degrees Fahrenheit: " << f << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl << endl;
        }
        break;
    default:
        cout << "You must enter a valid menu number.\n";
        break;
    }
}

double to_celsius(double fahrenheit) {
    if (fahrenheit > 212 || fahrenheit < 32) {
        throw invalid_argument("Error! Temperature must be from 32 to 212.");
    }
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

double to_fahrenheit(double celsius) {
    if (celsius > 100 || celsius < 0) {
        throw invalid_argument("Error! Temperature must be from 0 to 100.");
    }
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    return fahrenheit;
}