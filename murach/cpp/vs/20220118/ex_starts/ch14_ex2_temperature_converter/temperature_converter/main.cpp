#include <iostream>
#include <cmath>
#include "Temp.h"

using namespace std;

// declare functions
void display_menu();
void convert_temp();
/*
double to_celsius(double fahrenheit);
double to_fahrenheit(double celsius);
*/
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

/****************************************************
* Define functions
*****************************************************/

void display_menu() {
    cout << "MENU\n"
        << "1. Fahrenheit to Celsius\n"
        << "2. Celsius to Fahrenheit\n\n";
}

void convert_temp() {
    int option;
    cout << "Enter a menu option: ";
    cin >> option;

    Temp t;
    double f = 0.0;
    double c = 0.0;
    switch (option) {
    case 1:
        cout << "Enter degrees Fahrenheit: ";
        cin >> f;

        t.f_setter(f);
        cout << "Degrees Celsius: " << t.c_getter() << endl;
        /*
        c = to_celsius(f);
        c = round(c * 10) / 10;

        cout << "Degrees Celsius: " << c << endl;
        */
        break;
    case 2:
        cout << "Enter degrees Celsius: ";
        cin >> c;

        t.c_setter(c);
        cout << "Degrees Fahrenheit: " << t.f_getter() << endl;
        /*
        f = to_fahrenheit(c);
        f = round(f * 10) / 10;

        cout << "Degrees Fahrenheit: " << f << endl;
        */
        break;
    default:
        cout << "You must enter a valid menu number.\n";
        break;
    }
}
/*
double to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

double to_fahrenheit(double celsius) {
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    return fahrenheit;
}
*/