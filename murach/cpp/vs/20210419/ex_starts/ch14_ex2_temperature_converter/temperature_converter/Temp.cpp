#include "Temp.h"
#include <cmath>

Temp::Temp() {
    c = 0.0;
    f = 32.0;
}

void Temp::set_c(double val) {
    c = val;
    f = c * 9.0 / 5.0 + 32.0;
}

double Temp::get_c() const {
    double v = round(c * 10) / 10;
    return v;
}

void Temp::set_f(double val) {
    f = val;
    c = (f - 32.0) * 5.0 / 9.0;

}

double Temp::get_f() const {
    double v = round(f * 10) / 10;
    return v;
}