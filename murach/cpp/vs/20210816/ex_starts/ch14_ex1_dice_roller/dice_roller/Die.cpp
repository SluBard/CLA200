#include <cstdlib>
#include <ctime>
#include <string>
#include "Die.h"
#include <stdexcept>

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

std::string Die::get_image() const {
    std::string val;
    switch (get_value()) {
    case 1:
        val = " _____ \n"
            "|     |\n"
            "|  o  |\n"
            "|____ |\n";
        break;
    case 2:
        val = " _____ \n"
            "|o    |\n"
            "|     |\n"
            "|____o|\n";
        break;
    case 3:
        val = " _____ \n"
            "|o    |\n"
            "|  o  |\n"
            "|____o|\n";
        break;
    case 4:
        val = " _____ \n"
            "|o   o|\n"
            "|     |\n"
            "|o___o|\n";
        break;
    case 5:
        val = " _____ \n"
            "|o   o|\n"
            "|  o  |\n"
            "|o___o|\n";
        break;
    case 6:
        val = " _____ \n"
            "|o   o|\n"
            "|o   o|\n"
            "|o___o|\n";
        break;
    }
    return val;
}
void Die::set_value(int val) {
    if (val < 1 || val > 6) {
        throw invalid_argument("Die can only have value from 1-6.");
    }
    value = val;
}