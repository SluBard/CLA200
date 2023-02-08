#include <cstdlib>
#include <ctime>
#include <string>
#include "Die.h"
#include <stdexcept>
//#include <stdexcept>
using namespace std;
Die::Die() {
    srand(time(nullptr));  // seed the rand() function
    value = 1;
}

void Die::roll() {
    value = rand() % 6;    // value is >= 0 and < 6
    ++value;               // value is >= 1 and <= 6
}

int Die::get_value() const {
    return value;
}

string Die::get_image() const {
    string value = "";
    switch (get_value()) {
    case 6:
        value = " _____ \n" 
                "|o   o|\n" 
                "|o   o|\n" 
                "|o___o|\n";
        break;
    case 5:
        value = " _____ \n" 
                "|o   o|\n" 
                "|  o  |\n" 
                "|o___o|\n";
        break;
    case 4:
        value = " _____ \n" 
                "|o   o|\n" 
                "|     |\n" 
                "|o___o|\n";
        break;
    case 3:
        value = " _____ \n"
                "|o    |\n"
                "|  o  |\n"
                "|____o|\n";
        break;
    case 2:
        value = " _____ \n"
                "|o    |\n"
                "|     |\n"
                "|____o|\n";
        break;
    case 1:
        value = " _____ \n"
                "|     |\n"
                "|  o  |\n"
                "|____ |\n";
    }
    return value;
}
void Die::set_value(int val) {
    if (val < 1 || val >6) {
        throw invalid_argument("Die value must be from 1 to 6.");
    }
    else {
        value = val;
    }
}