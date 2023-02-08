#include <numeric>
#include "Dice.h"

Dice::Dice() {}

void Dice::add_die(Die die) {
    dice.push_back(die);
}

void Dice::roll_all() {
    for (Die& die : dice) {
        die.roll();
    }
}

std::vector<Die> Dice::get_dice() const {
    return dice;
}

int Dice::get_total() const {
    /*
    int total = 0;
    for (auto d : dice) {
        total += d.get_value();
    }
    return total;
    */
    return accumulate(dice.begin(), dice.end(), 0, [](int a, Die d)->int {return a + d.get_value(); });
  
}