#include <iostream>
#include "Temp.h"

using namespace std;

// declare functions
void display_menu();
void convert_temp();


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

    double f = 0.0;
    double c = 0.0;
    Temp t;
    switch (option) {
    case 1:
        cout << "Enter degrees Fahrenheit: ";
        cin >> f;

        t.set_f(f);

        cout << "Degrees Celsius: " << t.get_c() << endl;
        break;
    case 2:
        cout << "Enter degrees Celsius: ";
        cin >> c;

        t.set_c(c);

        cout << "Degrees Fahrenheit: " << t.get_f() << endl;
        break;
    default:
        cout << "You must enter a valid menu number.\n";
        break;
    }
}