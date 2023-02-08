#include <cstdlib>
#include <ctime>
#include <string>
#include "Die.h"
#include <stdexcept>

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
    std::string image = "";
    switch (get_value()) {
    case 1:
        image = " _____ \n"
            "|     |\n"
            "|  o  |\n"
            "|____ |\n";
        break;
    case 2:
        image = " _____ \n"
            "|o    |\n"
            "|     |\n"
            "|____o|\n";
        break;
    case 3:
        image = " _____ \n"
            "|o    |\n"
            "|  o  |\n"
            "|____o|\n";
        break;
    case 4:
        image = " _____ \n"
            "|o   o|\n"
            "|     |\n"
            "|o___o|\n";
        break;
    case 5:
        image = " _____ \n"
            "|o   o|\n"
            "|  o  |\n"
            "|o___o|\n";
        break;
    case 6:
        image = " _____ \n"
            "|o   o|\n"
            "|o   o|\n"
            "|o___o|\n";
        break;      
    }
    return image;
}

void Die::set_value(int val) {
    if (val < 1 || val > 6) {
        throw std::invalid_argument("set_value must called with values between 1 and 6.");
    }
    value = val;
}