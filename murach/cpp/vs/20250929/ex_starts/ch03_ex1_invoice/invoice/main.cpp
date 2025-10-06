#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // display title
    cout << "The Invoice Total Calculator 2.0\n\n";

    // get input
    char customer_type;
    cout << "Enter customer type (c/r/w): ";
    cin >> customer_type;

    double subtotal;
    cout << "Enter subtotal:            ";
    cin >> subtotal;

    // set discount percent
    double discount_percent;
    switch (customer_type)
    {
    case 'c':
    case 'C':
        discount_percent = 0.25;
        break;
    case 'r':
    case 'R':
        if (subtotal < 100) {
            discount_percent = .0;
        }
        else if (subtotal >= 100 && subtotal < 250) {
            discount_percent = .1;
        }
        else {
            discount_percent = .2;
        }
        break;
    case 'w':
    case 'W':
        if (subtotal < 500) {
            discount_percent = .4;
        }
        else {
            discount_percent = .5;
        }
        break;
    default:
        discount_percent = .0;
        break;
    }
    /*
    if ( customer_type == 'r' || customer_type == 'R') {           // RETAIL
        if (subtotal < 100) {
            discount_percent = .0;
        }
        else if (subtotal >= 100 && subtotal < 250) {
            discount_percent = .1;
        }
        else {
            discount_percent = .2;
        }
    }
    else if (tolower(customer_type) == 'w') {     // WHOLESALE
        if (subtotal < 500) {
            discount_percent = .4;
        }
        else {
            discount_percent = .5;
        }
    }
    else if (customer_type == 'c' || customer_type == 'C') {
        discount_percent = .25;
    }
    else {                                       // OTHER
        discount_percent = .0;
    }
    */

    // calculate and round results
    double discount_amount = subtotal * discount_percent;
    discount_amount = round(discount_amount * 100) / 100;

    double invoice_total = subtotal - discount_amount;
    invoice_total = round(invoice_total * 100) / 100;

    // display output
    cout << "Discount percent:          " << discount_percent << endl
         << "Discount amount:           " << discount_amount << endl
         << "Invoice total:             " << invoice_total << endl << endl;

    cout << "Bye!\n\n";
}