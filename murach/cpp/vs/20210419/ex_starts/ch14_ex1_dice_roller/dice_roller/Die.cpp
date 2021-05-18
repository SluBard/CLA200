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

void Die::set_value(int i) {
    if (i < 1 || i > 6) {
        throw std::invalid_argument("Value must be between 1 and 6 inclusive.\n");
    }
    value = i;
}
std::string Die::get_image() const {
    std::string image = "";
    switch (get_value()) {
    case 6:
        image = " _____ \n";
        image += "|o   o|\n";
        image += "|o   o|\n";
        image += "|o___o|\n";
        break;

    case 5:
        image = " _____ \n";
        image += "|o   o|\n";
        image += "|  o  |\n";
        image += "|o___o|\n";
        break;

    case 4:
        image = " _____ \n";
        image += "|o   o|\n";
        image += "|     |\n";
        image += "|o___o|\n";
        break;

    case 3:
        image = " _____ \n";
        image += "|o    |\n";
        image += "|  o  |\n";
        image += "|____o|\n";
        break;

    case 2:
        image = " _____ \n";
        image += "|o    |\n";
        image += "|     |\n";
        image += "|____o|\n";
        break;

    case 1:
        image = " _____ \n";
        image += "|     |\n";
        image += "|  o  |\n";
        image += "|____ |\n";
        break;
    }
    return image;
}