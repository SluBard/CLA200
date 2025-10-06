#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Die.h"


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
    std::string image="";

    switch (value) {
    case 6:
        image = 
            " _____ \n"
            "|o   o|\n"
            "|o   o|\n"
            "|o___o|\n";
        break;

    case 5:
        image = 
            " _____ \n"
            "|o   o|\n"
            "|  o  |\n"
            "|o___o|\n";
        break;

    case 4:
        image =
            " _____ \n"
            "|o   o|\n"
            "|     |\n"
            "|o___o|\n";
        break;

    case 3:
        image =
            " _____ \n"
            "|o    |\n"
            "|  o  |\n"
            "|____o|\n";
        break;

    case 2:
        image =
            " _____ \n"
            "|o    |\n"
            "|     |\n"
            "|____o|\n";
        break;

    case 1:
        image =
            " _____ \n"
            "|     |\n"
            "|  o  |\n"
            "|____ |\n";
    }
    return image;
}
void Die::set_value(int p_value) {
    if ( p_value < 1 || p_value > 6) {
        throw std::invalid_argument("Value must be between 1 and 6.");
    }
    value = p_value;
}